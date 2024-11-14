#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int mergeStones(vector<int> &stones, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minhe;
        for (int i = 0; i < stones.size(); i++)
        {
            int inco = 0;
            for (int j = 0; j < k; j++)
            {
                inco += stones[j + i];
            }
            pair<int, int> pa = make_pair(inco, i);
            minhe.push(pa);
        }
    }

    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        ans[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            ans[i] += ans[i - 1];
        }
        int la = INT_MIN;

        return la;
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int no_nodes = points.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < no_nodes; i++)
        {
            vec[i] = make_pair(points[i][0], points[i][1]);
        }
        // creating adj list
        unordered_map<int, vector<pair<int, long long>>> adj; // point->//vector(point,weight)
        for (int i = 0; i < no_nodes; i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            for (int j = 0; j < no_nodes; j++)
            {
                int xj = points[j][0];
                int yj = points[j][1];
                adj[i].push_back(make_pair(j, abs(xj - x) + abs(yj - y)));
            }
        }

        // starting the algo
        vector<int> key(no_nodes, INT_MAX);
        vector<bool> mst(no_nodes, false);
        vector<int> parent(no_nodes, -1);
        key[0] = 0;
        parent[0] = -1;

        int u = 0;

        mst[u] = true;
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v])
            {
                key[v] = w;
                mst[v] = true;
                parent[v] = u;
            }
        }

        int sum = 0;
        for (int i = 0; i < no_nodes; i++)
        {
            sum += key[i];
        }
        return sum;
    }
};
int main()
{
}