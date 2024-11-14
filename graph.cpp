#include <bits/stdc++.h>
using namespace std;
template <typename Ty>
class graph
{
public:
    unordered_map<Ty>, list<Ty> > adj;

    void addedge(Ty u, Ty v, bool direction)
    {
        adj[u].push_back(v);
        if (!direction)
        {
            adj[v].push_back(u);
        }
    }
    void printlist()
    {
        for(auto i:adj)
        {
            cout<<i.first<<"-> ";
            for(auto j:i.second)
            {
                cout<<j<<",";
            }
        }
        cout<<endl;
    }
};
//BFS TRAVERSAL
void bfs(int in,vector<int> &ans,vector<vector<int> > &adj,vector<bool> &visited)
{
    queue<int> q;
    q.push(in);
    visited[in]=true;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        ans.push_back(t);
        for(auto i:adj[t])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }

}
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    vector<int> ans;
    vector<bool> visited;
    for(int i=0;i<n;i++) visited[i]=false;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bfs(i,ans,adj,visited);
        }
    }
    return ans;
}

//DFS TRAVESAL
void adjlist(vector<vector<int> > &edges,unordered_map <int,vector<int> > &adj)
{
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
}
void dfs(int node,vector<int> ans,unordered_map <int,vector<int> > &adj,vector<bool> &visited)
{
    visited[node]=true;
    ans.push_back(node);
    for(auto i:adj[node])
    {
        if(!visited[i])
        {
            dfs(i,ans,adj,visited);
        }
    }
}
vector<vector<int>> depthFirstSearch(int v, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector <int> > fans;
    vector<bool> visited;
    unordered_map <int,vector<int> > adj;
    adjlist(edges,adj);
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            vector<int> ans;
            dfs(i,ans,adj,visited);
            fans.push_back(ans);
        }
    }
    return fans;
}