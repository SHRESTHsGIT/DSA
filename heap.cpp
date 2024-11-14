#include <iostream>
using namespace std;
class heap
{
    public:
    int arr[100];
    int size;
    heap()
    {
        size=0;
    }
    void insert(int val)
    {
        size+=1;
        int index=size;
        arr[index]=val;
        while(index>1)
        {
            int parent=index/2;
            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }


    int pop()
    {
        
        if(size==0)
        {
            cout<<"empty heap"<<endl;
            return -1;
        }

        int re=arr[size];
        swap(arr[1],arr[size]);
        size--;

        int i=1;
        while(size>i)
        {
            int parent =i;
            int left=2*i;
            int right=2*i+1;
            if( left<size && arr[parent]<arr[left])
            {
                swap(arr[parent],arr[left]);
                i=left;
            }
            else if( right<size && arr[parent]<arr[right])
            {
                swap(arr[parent],arr[right]);
                i=right;
            }
            else{
                return re;
            }
            return re;

        }
    }

    int top()
    {
        return arr[1];
    }
};



void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left < n && arr[largest]<arr[left])
    {
        largest=left;
    }

    if(left < n && arr[largest]<arr[right])
    {
        largest=right;
    }

    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapifyloop(int arr[],int n)
{
    for(int i=n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }
}




void heapsort(int arr[],int n)
{
    heapifyloop(arr,n);
    int size=n;
    while(size>1)
    {
        swap(arr[1],arr[n]);

        size--;
        heapify(arr,size,1);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{

    return 0;
}