#include <bits/stdc++.h>

void dfs(vector<vector<int>> &graph, vector<bool> &visited, const int i, vector<int> &res)
{

    visited[i] = true;

    res.push_back(i);

    for (int j = 0; j < graph[i].size(); j++)
    {

        if (visited[graph[i][j]] == false)
        {

            dfs(graph, visited, graph[i][j], res);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{

    vector<vector<int>> graph(V);

    for (int e = 0; e < E; e++)
    {

        graph[edges[e][0]].push_back(edges[e][1]);

        graph[edges[e][1]].push_back(edges[e][0]);
    }

    vector<vector<int>> ans;

    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {

        if (visited[i] == false)
        {

            vector<int> res;

            dfs(graph, visited, i, res);

            ans.push_back(res);
        }
    }

    return ans;
}