// Standard include for C++ on Mac
#include "stdc++.cpp"
#include <iomanip>

using namespace std;

class Process {
public:
    int id;                  // Process identifier
    int arrival_time;        // Time when process arrives in the system
    int total_cpu_burst;     // Total CPU time required
    int remaining_cpu_burst; // Remaining CPU time to complete
    int cpu_burst_interval;  // Max CPU time before I/O
    int io_burst;            // I/O operation time
    int response_time;       // Time from arrival to first CPU allocation
    int completion_time;     // Time when process completes execution
    int current_cpu_progress; // Progress in current CPU burst interval
    bool in_io;              // Flag if process is in I/O
    int io_completion_time;  // Time remaining in I/O
    
    // Constructor to initialize process attributes
    Process(int _id, int _at, int _total_cpu, int _cpu_interval, int _io_burst)
    {
        id = _id;
        arrival_time = _at;
        total_cpu_burst = _total_cpu;
        remaining_cpu_burst = _total_cpu;
        cpu_burst_interval = _cpu_interval;
        io_burst = _io_burst;
        
        current_cpu_progress = _cpu_interval;
        in_io = false;
        io_completion_time = 0;
    }
};

// Comparator for priority queue - sorts processes by remaining CPU burst time
struct CompareCPUTime {
    bool operator()(Process *const &p1, Process *const &p2) {
        // If current CPU progress is different, prioritize the one with less time
        if (p1->current_cpu_progress != p2->current_cpu_progress)
            return p1->current_cpu_progress > p2->current_cpu_progress; // Note: inverted for priority queue
        // Break ties by arrival time (earlier arrival gets priority)
        return p1->arrival_time > p2->arrival_time;
    }
};

// Shortest Remaining Time First (SRTF) CPU scheduling algorithm
void srtf(vector<Process> &P) {
    // Priority queue for processes ready for CPU execution
    priority_queue<Process*, vector<Process*>, CompareCPUTime> cpu_queue;
    // Queue for processes in I/O state
    queue<Process*> io_queue;
    
    int time = 0;           // Current simulation time
    int completed = 0;      // Number of completed processes
    
    // Additional metrics for analysis
    vector<int> wait_times(P.size(), 0);
    vector<int> turnaround_times(P.size(), 0);
    
    // Simulation loop - runs until all processes complete
    while (completed < P.size()) {
        // Check for new process arrivals at current time
        for (Process &p : P) {
            if (p.arrival_time == time) {
                cpu_queue.push(&p);
            }
        }
        
        // Select the process with shortest remaining time
        Process *curr_p = nullptr;
        if (!cpu_queue.empty()) {
            curr_p = cpu_queue.top();
            cpu_queue.pop();
        }
        
        // Process the selected process
        if (curr_p) {
            // If this is the first time the process gets CPU, record response time
            if (curr_p->remaining_cpu_burst == curr_p->total_cpu_burst)
                curr_p->response_time = time - curr_p->arrival_time;
            
            // Execute the process for one time unit
            curr_p->remaining_cpu_burst--;
            curr_p->current_cpu_progress--;
            
            // Check if process has completed
            if (curr_p->remaining_cpu_burst == 0) {
                curr_p->completion_time = time + 1;
                turnaround_times[curr_p->id] = curr_p->completion_time - curr_p->arrival_time;
                wait_times[curr_p->id] = turnaround_times[curr_p->id] - curr_p->total_cpu_burst;
                completed++;
            } 
            // Check if process needs to perform I/O
            else if (curr_p->current_cpu_progress == 0) {
                curr_p->current_cpu_progress = curr_p->cpu_burst_interval;
                curr_p->io_completion_time = curr_p->io_burst;
                io_queue.push(curr_p);
            } 
            // Otherwise, put the process back in the CPU queue
            else {
                cpu_queue.push(curr_p);
            }
        }
        
        // Handle I/O operations - using original implementation
        if (!io_queue.empty()) {
            Process *front_p = io_queue.front();
            front_p->io_completion_time--;
            if (front_p->io_completion_time == 0) {
                io_queue.pop();
                cpu_queue.push(front_p);
            }
        }
        
        time++;
    }
    // Create and open output file
    ofstream outfile("srtf_scheduling_results.txt");
    outfile << "SRTF Scheduling Results" << endl;
    outfile << "======================" << endl << endl;
    
    // Header
    outfile << setw(12) << left << "Process ID" 
            << setw(14) << left << "Arrival Time" 
            << setw(16) << left << "Completion Time" 
            << setw(14) << left << "Response Time" 
            << setw(16) << left << "Turnaround Time" 
            << setw(14) << left << "Waiting Time" << endl;
            
    outfile << string(86, '-') << endl;
    
    // Data rows
    for (Process &p : P) {
        outfile << setw(12) << left << ("P" + to_string(p.id))
                << setw(14) << left << p.arrival_time
                << setw(16) << left << p.completion_time
                << setw(14) << left << p.response_time
                << setw(16) << left << turnaround_times[p.id]
                << setw(14) << left << wait_times[p.id] << endl;
    }
    
    outfile << endl;
    
    // Calculate and display average metrics
    double avg_response = 0, avg_turnaround = 0, avg_wait = 0;
    for (size_t i = 0; i < P.size(); i++) {
        avg_response += P[i].response_time;
        avg_turnaround += turnaround_times[i];
        avg_wait += wait_times[i];
    }
    avg_response /= P.size();
    avg_turnaround /= P.size();
    avg_wait /= P.size();
    
    outfile << "Summary:" << endl;
    outfile << "--------" << endl;
    outfile << "Average Response Time: " << avg_response << endl;
    outfile << "Average Turnaround Time: " << avg_turnaround << endl;
    outfile << "Average Waiting Time: " << avg_wait << endl;
    
    // Also print to console that the output has been saved
    cout << "SRTF scheduling results have been saved to 'scheduling_results.txt'" << endl;
    
    // Close the file
    outfile.close();
}

struct CompareRemainingCPUBurst {
    bool operator()(Process* const& p1, Process* const& p2) {
        return p1->remaining_cpu_burst > p2->remaining_cpu_burst;
    }
};

void sjf(vector<Process>& P) {
    // Priority queue for processes ready for CPU execution
    priority_queue<Process*, vector<Process*>, CompareRemainingCPUBurst> ready_queue;
    // Queue for processes in I/O state
    queue<Process*> io_queue;
    
    int time = 0;           // Current simulation time
    int completed = 0;      // Number of completed processes
    
    // Additional metrics for analysis
    vector<int> wait_times(P.size(), 0);
    vector<int> turnaround_times(P.size(), 0);
    
    // Initialize response times
    for (Process& p : P) {
        p.response_time = -1;
    }
    
    // Simulation loop - runs until all processes complete
    while (completed < P.size()) {
        // Check for new process arrivals at current time
        for (Process& p : P) {
            if (p.arrival_time == time) {
                ready_queue.push(&p);
            }
        }
        
        // If no process is ready but processes exist that aren't completed,
        // advance time to next arrival or I/O completion
        if (ready_queue.empty() && completed < P.size()) {
            int next_event_time = INT_MAX;
            
            // Find next arrival time
            for (Process& p : P) {
                if (p.completion_time == -1 && p.arrival_time > time && !p.in_io) {
                    next_event_time = min(next_event_time, p.arrival_time);
                }
            }
            
            // If there are no more arrivals, just increment time by 1
            if (next_event_time == INT_MAX) {
                time++;
            } else {
                time = next_event_time;
            }
            
            // Handle I/O operations
            if (!io_queue.empty()) {
                Process* front_p = io_queue.front();
                front_p->io_completion_time--;
                if (front_p->io_completion_time == 0) {
                    io_queue.pop();
                    ready_queue.push(front_p);
                }
            }
            
            continue;
        }
        
        // Select the process with shortest job time (non-preemptive)
        if (!ready_queue.empty()) {
            Process* curr_p = ready_queue.top();
            ready_queue.pop();
            
            // If this is the first time the process gets CPU, record response time
            if (curr_p->response_time == -1) {
                curr_p->response_time = time - curr_p->arrival_time;
            }
            
            // For SJF, execute the entire CPU burst at once
            int executed_time = 0;
            while (curr_p->remaining_cpu_burst > 0 && curr_p->current_cpu_progress > 0) {
                executed_time++;
                curr_p->remaining_cpu_burst--;
                curr_p->current_cpu_progress--;
                
                // Handle I/O operations during execution
                if (!io_queue.empty()) {
                    Process* front_p = io_queue.front();
                    front_p->io_completion_time--;
                    if (front_p->io_completion_time == 0) {
                        io_queue.pop();
                        ready_queue.push(front_p);
                    }
                }
                
                time++;
                
                // Check for new arrivals during execution
                for (Process& p : P) {
                    if (p.arrival_time == time) {
                        ready_queue.push(&p);
                    }
                }
            }
            
            // Check if process has completed all CPU bursts
            if (curr_p->remaining_cpu_burst == 0) {
                curr_p->completion_time = time;
                turnaround_times[curr_p->id] = curr_p->completion_time - curr_p->arrival_time;
                wait_times[curr_p->id] = turnaround_times[curr_p->id] - curr_p->total_cpu_burst;
                completed++;
            } 
            // Check if process needs to perform I/O
            else if (curr_p->current_cpu_progress == 0) {
                curr_p->current_cpu_progress = curr_p->cpu_burst_interval;
                curr_p->io_completion_time = curr_p->io_burst;
                curr_p->in_io = true;
                io_queue.push(curr_p);
            }
        } else {
            // If no process is in ready queue, advance time
            time++;
            
            // Handle I/O operations
            if (!io_queue.empty()) {
                Process* front_p = io_queue.front();
                front_p->io_completion_time--;
                if (front_p->io_completion_time == 0) {
                    io_queue.pop();
                    front_p->in_io = false;
                    ready_queue.push(front_p);
                }
            }
        }
    }
    
    // Create and open output file
    ofstream outfile("sjf_scheduling_results.txt");
    outfile << "SJF Scheduling Results" << endl;
    outfile << "======================" << endl << endl;
    
    // Header
    outfile << setw(12) << left << "Process ID" 
            << setw(14) << left << "Arrival Time" 
            << setw(16) << left << "Completion Time" 
            << setw(14) << left << "Response Time" 
            << setw(16) << left << "Turnaround Time" 
            << setw(14) << left << "Waiting Time" << endl;
            
    outfile << string(86, '-') << endl;
    
    // Data rows
    for (Process& p : P) {
        outfile << setw(12) << left << ("P" + to_string(p.id))
                << setw(14) << left << p.arrival_time
                << setw(16) << left << p.completion_time
                << setw(14) << left << p.response_time
                << setw(16) << left << turnaround_times[p.id]
                << setw(14) << left << wait_times[p.id] << endl;
    }
    
    outfile << endl;
    
    // Calculate and display average metrics
    double avg_response = 0, avg_turnaround = 0, avg_wait = 0;
    for (size_t i = 0; i < P.size(); i++) {
        avg_response += P[i].response_time;
        avg_turnaround += turnaround_times[i];
        avg_wait += wait_times[i];
    }
    avg_response /= P.size();
    avg_turnaround /= P.size();
    avg_wait /= P.size();
    
    outfile << "Summary:" << endl;
    outfile << "--------" << endl;
    outfile << "Average Response Time: " << avg_response << endl;
    outfile << "Average Turnaround Time: " << avg_turnaround << endl;
    outfile << "Average Waiting Time: " << avg_wait << endl;
    
    // Also print to console that the output has been saved
    cout << "SJF scheduling results have been saved to 'sjf_scheduling_results.txt'" << endl;
    
    // Close the file
    outfile.close();
}


void round_robin(vector<Process> &P, int quantum) {
    queue<Process*> ready_queue;
    vector<int> wait_times(P.size(), 0), turnaround_times(P.size(), 0);
    int time = 0, completed = 0;
    
    vector<bool> in_queue(P.size(), false);
    int index = 0;
    
    // Initialize remaining_cpu_burst if not already done
    for (auto &p : P) {
        if (p.remaining_cpu_burst <= 0) {
            p.remaining_cpu_burst = p.total_cpu_burst;
        }
    }
    
    while (completed < P.size()) {
        // Check for newly arrived processes
        while (index < P.size() && P[index].arrival_time <= time) {
            ready_queue.push(&P[index]);
            in_queue[index] = true;
            index++;
        }
        
        if (!ready_queue.empty()) {
            Process *curr_p = ready_queue.front();
            ready_queue.pop();
            
            // Record response time (first time process gets CPU)
            if (curr_p->response_time == -1)
                curr_p->response_time = time - curr_p->arrival_time;
            
            int execute_time = min(quantum, curr_p->remaining_cpu_burst);
            curr_p->remaining_cpu_burst -= execute_time;
            time += execute_time;
            
            // Check for newly arrived processes during this time slice
            while (index < P.size() && P[index].arrival_time <= time) {
                ready_queue.push(&P[index]);
                in_queue[index] = true;
                index++;
            }
            
            if (curr_p->remaining_cpu_burst > 0) {
                ready_queue.push(curr_p);
            } else {
                // Process is complete
                curr_p->completion_time = time;
                turnaround_times[curr_p->id] = curr_p->completion_time - curr_p->arrival_time;
                // Correct calculation for waiting time
                wait_times[curr_p->id] = turnaround_times[curr_p->id] - curr_p->total_cpu_burst;
                completed++;
            }
        } else {
            // CPU idle, advance time
            time++;
        }
    }
    
    ofstream outfile("round_robin_scheduling_results.txt");
    outfile << "Round Robin Scheduling Results" << endl;
    outfile << "==============================" << endl << endl;
    outfile << setw(12) << left << "Process ID"
            << setw(14) << left << "Arrival Time"
            << setw(16) << left << "Completion Time"
            << setw(14) << left << "Response Time"
            << setw(16) << left << "Turnaround Time"
            << setw(14) << left << "Waiting Time" << endl;
    outfile << string(86, '-') << endl;
    
    double avg_response = 0, avg_turnaround = 0, avg_wait = 0;
    for (Process &p : P) {
        // Ensure waiting time is never negative
        if (wait_times[p.id] < 0) {
            wait_times[p.id] = 0;
        }
        
        outfile << setw(12) << left << ("P" + to_string(p.id))
                << setw(14) << left << p.arrival_time
                << setw(16) << left << p.completion_time
                << setw(14) << left << p.response_time
                << setw(16) << left << turnaround_times[p.id]
                << setw(14) << left << wait_times[p.id] << endl;
        avg_response += p.response_time;
        avg_turnaround += turnaround_times[p.id];
        avg_wait += wait_times[p.id];
    }
    
    avg_response /= P.size();
    avg_turnaround /= P.size();
    avg_wait /= P.size();
    
    outfile << "\nSummary:" << endl;
    outfile << "--------" << endl;
    outfile << "Average Response Time: " << avg_response << endl;
    outfile << "Average Turnaround Time: " << avg_turnaround << endl;
    outfile << "Average Waiting Time: " << avg_wait << endl;
    outfile.close();
    
    cout << "Round Robin scheduling results saved to 'round_robin_scheduling_results.txt'" << endl;
}


void vrr(vector<Process> &P) {
    // Queue for processes ready for CPU execution
    queue<Process*> cpu_queue;
    // Queue for processes in I/O state
    queue<Process*> io_queue;
    
    int time = 0;           // Current simulation time
    int completed = 0;      // Number of completed processes
    
    // Additional metrics for analysis
    vector<int> wait_times(P.size(), 0);
    vector<int> turnaround_times(P.size(), 0);
    
    // Simulation loop - runs until all processes complete
    while (completed < P.size()) {
        // Check for new process arrivals at current time
        for (Process &p : P) {
            if (p.arrival_time == time) {
                cpu_queue.push(&p);
            }
        }
        
        // Process the next process in the queue
        if (!cpu_queue.empty()) {
            Process *curr_p = cpu_queue.front();
            cpu_queue.pop();
            
            // If this is the first time the process gets CPU, record response time
            if (curr_p->remaining_cpu_burst == curr_p->total_cpu_burst)
                curr_p->response_time = time - curr_p->arrival_time;
            
            // Run process for one quantum or until CPU burst is completed
            int time_slice = min(5, curr_p->remaining_cpu_burst);
            curr_p->remaining_cpu_burst -= time_slice;
            curr_p->current_cpu_progress -= time_slice;
            
            // If the process has completed its CPU burst
            if (curr_p->remaining_cpu_burst == 0) {
                curr_p->completion_time = time + time_slice;
                turnaround_times[curr_p->id] = curr_p->completion_time - curr_p->arrival_time;
                wait_times[curr_p->id] = turnaround_times[curr_p->id] - curr_p->total_cpu_burst;
                completed++;
            }
            // If process needs I/O
            else if (curr_p->current_cpu_progress == 0) {
                curr_p->current_cpu_progress = curr_p->cpu_burst_interval;
                curr_p->io_completion_time = curr_p->io_burst;
                io_queue.push(curr_p);
            } else {
                // Process still needs more CPU, return it to the queue
                cpu_queue.push(curr_p);
            }
            
            time += time_slice;
        }
        
        // Handle I/O operations - only processes in I/O are handled here
        if (!io_queue.empty()) {
            Process *front_p = io_queue.front();
            front_p->io_completion_time--;
            if (front_p->io_completion_time == 0) {
                io_queue.pop();
                cpu_queue.push(front_p);
            }
        }
    }
    
    // Create and open output file
    ofstream outfile("vrr_scheduling_results.txt");
    outfile << "Virtual Round Robin (VRR) Scheduling Results" << endl;
    outfile << "============================================" << endl << endl;
    
    // Header
    outfile << setw(12) << left << "Process ID" 
            << setw(14) << left << "Arrival Time" 
            << setw(16) << left << "Completion Time" 
            << setw(14) << left << "Response Time" 
            << setw(16) << left << "Turnaround Time" 
            << setw(14) << left << "Waiting Time" << endl;
            
    outfile << string(86, '-') << endl;
    
    // Data rows
    for (Process &p : P) {
        outfile << setw(12) << left << ("P" + to_string(p.id))
                << setw(14) << left << p.arrival_time
                << setw(16) << left << p.completion_time
                << setw(14) << left << p.response_time
                << setw(16) << left << turnaround_times[p.id]
                << setw(14) << left << wait_times[p.id] << endl;
    }
    
    outfile << endl;
    
    // Calculate and display average metrics
    double avg_response = 0, avg_turnaround = 0, avg_wait = 0;
    for (size_t i = 0; i < P.size(); i++) {
        avg_response += P[i].response_time;
        avg_turnaround += turnaround_times[i];
        avg_wait += wait_times[i];
    }
    avg_response /= P.size();
    avg_turnaround /= P.size();
    avg_wait /= P.size();
    
    outfile << "Summary:" << endl;
    outfile << "--------" << endl;
    outfile << "Average Response Time: " << avg_response << endl;
    outfile << "Average Turnaround Time: " << avg_turnaround << endl;
    outfile << "Average Waiting Time: " << avg_wait << endl;
    
    // Also print to console that the output has been saved
    cout << "VRR scheduling results have been saved to 'vrr_scheduling_results.txt'" << endl;
    
    // Close the file
    outfile.close();
}


int main() {
    // Create test processes with parameters (id, arrival_time, total_cpu_burst, cpu_burst_interval, io_burst)
    vector<Process> P;
P.push_back(Process(0, 0, 24, 5, 2));
P.push_back(Process(1, 3, 17, 6, 3));
P.push_back(Process(2, 8, 50, 5, 2));
P.push_back(Process(3, 15, 10, 6, 3));
    
    // Run the SRTF scheduling algorithm
    srtf(P);
    sjf(P);
    round_robin(P,5);
    vrr(P);
    return 0;
}