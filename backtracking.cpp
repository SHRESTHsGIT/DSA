
#include "bits/stdc++.cpp"
using namespace std;
// #RAT IN A MAZE
void solve(int x, int y, vector<vector<int>> &arr, int &n, vector<string> &ans, vector<vector<bool>> vis, string path)
{
    // base condition
    if (x == n - 1 && y == n - 1)
    {

        ans.push_back(path);
        return;
    }

    int ynew = y + 1;
    int xnew = x;
    // D L R U
    // d

    if ((ynew >= 0 && ynew < n) && (xnew >= 0 && xnew < n) && (arr[xnew][ynew] == 1) && (vis[xnew][ynew] != 1))
    {
        vis[x][y] = true;

        solve(xnew, ynew, arr, n, ans, vis, path + 'D');
        vis[x][y] = false;
    }

    // L
    xnew = x - 1;
    ynew = y;
    if ((ynew >= 0 && ynew < n) && (xnew >= 0 && xnew < n) && (arr[xnew][ynew] == 1) && (vis[xnew][ynew] != 1))
    {
        vis[x][y] = true;

        solve(xnew, ynew, arr, n, ans, vis, path + 'L');
        vis[x][y] = false;
    }

    // R
    xnew = x + 1;
    ynew = y;
    if ((ynew >= 0 && ynew < n) && (xnew >= 0 && xnew < n) && (arr[xnew][ynew] == 1) && (vis[xnew][ynew] != 1))
    {
        vis[x][y] = true;

        solve(xnew, ynew, arr, n, ans, vis, path + 'R');
        vis[x][y] = false;
    }
    // U
    xnew = x;
    ynew = y - 1;
    if ((ynew >= 0 && ynew < n) && (xnew >= 0 && xnew < n) && (arr[xnew][ynew] == 1) && (vis[xnew][ynew] != 1))
    {
        vis[x][y] = true;

        solve(xnew, ynew, arr, n, ans, vis, path + 'U');
        vis[x][y] = false;
    }
    return;
}
vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;

    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string path = "";
    if (arr[0][0] == 0)
    {
        return ans;
    }
    solve(0, 0, arr, n, ans, visited, path);
    return ans;
    // Write your code here.
}

// N  - QUEEN PROBLEM

void addsolution(vector<vector<int>> &board,vector<vector<string> > &ans,int n)
{
    vector <string> temp;
    for(int i=0;i<n;i++)//y
    {
        string t;
        for(int j=0;j<n;j++)//x
        {
            if( board[j][i]==1)
            {
                t=t+'Q';
            }
            else{
                t=t+'.';
            }
        }
        temp.push_back(t);
    }
    ans.push_back(temp);
}
bool issafe(int row,int col,vector<vector<int>> &board,int &n)
{
    int x=col;
    int y=row;
    while(col>=0)
    {
        if(board[x][y]==1) return false;
        x--;
    }
    x=col;
    y=row;
    while(x>=0&& y>=0)
    {
        if(board[x][y]==1) return false;
        y--;
        x--;
        
    }
    x=col;
    y=row;
    while(x>=0&& n>y)
    {
        if(board[x][y]==1) return false;
        y++;
        x--;
        
    }
    return true;
}
void solve2(int col,vector<vector<string> > &ans, vector<vector<int>> &board,int n)
{
    if(col ==n)
    {
        addsolution(board,ans,n);
        return;
    }

    for(int row=0;row<n;row++)//row=y,col=x
    {
        if(issafe(row,col,board,n))
        {
            board[col][row]=1;
            solve2(col+1,ans,board,n);
            //bactrack
            board[col][row]=0;
        }
    }
}
    vector<vector<string>> solveNQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<string> >  ans;
    solve2(0, ans, board, n);
}