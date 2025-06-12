#include "bits/stdc++.cpp"
using namespace std;
const int k = 1e5;
vector<int> arr(k, -1);
// You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.

// Note:
// You have an infinite number of elements of each type.
// For example
// If N=3 and X=7 and array elements are [1,2,3].
// Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
// Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
// Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
// Hence the output is 3.

int solve_rec(vector<int> &num, int x)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;
    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solve_rec(num, x - num[i]);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }
    return mini;
}

int solverec2(vector<int> &dp, vector<int> &num, int x)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;
    if (dp[x] != -1)
    {
        return dp[x];
    }
    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {

        int ans = solverec2(dp, num, x - num[i]);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }
    dp[x] = mini;
    return dp[x];
}
int solvetab(vector<int> &num, int x)
{
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
                dp[i] = min(dp[i], dp[i - num[j]] + 1);
        }
    }
    if (dp[x] == INT_MAX)
        return -1;
    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
    vector<int> dp(x + 1, -1);
    int ans = solverec2(dp, num, x);
    if (ans == INT_MAX)
        return -1;
    return ans;
}

//

/*Problem statement
You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

Note:
A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving the remaining elements in their original order.*/
int solvere3(vector<int> &nums, int i)
{
    if (i >= nums.size())
        return 0;
    // i inclu
    int inclu = nums[i] + solvere3(nums, i + 2);
    // i exclu
    int exclu = solvere3(nums, i + 1);
    return max(inclu, exclu);
}
int solvemem(vector<int> &nums, int i, vector<int> &dp)
{
    if (i >= nums.size())
        return 0;
    if (dp[i] != INT_MIN)
        return dp[i];
    int inclu = nums[i] + solvemem(nums, i + 2, dp);

    int exclu = solvemem(nums, i + 1, dp);
    dp[i] = max(inclu, exclu);
    return dp[i];
}
int solvetab(vector<int> &nums)
{
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 1; i < nums.size(); i++)
    {
        int inclu = nums[i] + dp[i - 2];
        int exclu = 0 + dp[i - 1];
        dp[i] = max(inclu, exclu);
    }
    return dp[nums.size() - 1];
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // return solvere3(nums, 0);
    //  Write your code here.
}

/*A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.

Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.*/
long long int dearr(int n, int i, int j)
{
    if (i == n - 1)
        return 1;
    int c = 0;
    for (int j = 0; j < n; j++)
    {
        if (j != i)
        {
        }
    }
}
long long int countDerangements(int n)
{
    // Write your code here.
}
/*
Ninja has given a fence, and he gave a task to paint this fence. The fence has 'N' posts, and Ninja has 'K' colors. Ninja wants to paint the fence so that not more than two adjacent posts have the same color.

Ninja wonders how many ways are there to do the above task, so he asked for your help.

Your task is to find the number of ways Ninja can paint the fence. Print the answer modulo 10^9 + 7.*/
int now(int n, int k)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return k;

    int ways = (now(n - 1, k) * (k - 1)) + (now(n - 2, k) * (k - 1));
    return ways;
}
int numberOfWays(int n, int k)
{
    return now(n, k);
    // Write your code here.
}
int solve(vector<int> &weight, vector<int> &value, int n, int maxWeight, int ans, int i)
{
    if (i >= weight.size() && maxWeight <= 0)
        return ans;

    // include
    int ans1 = ans;
    if (weight[i] <= maxWeight)
        ans1 = solve(weight, value, n, maxWeight - weight[i], ans + value[i], i++);
    int ans2 = solve(weight, value, n, maxWeight, ans, i++);
    return max(ans1, ans2);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> weight = {2, 3, 1};

    // Vector with elements -3, 5, 2
    vector<int> value = {3, 5, 2};
    return solve(weight, value, n, 5, 0, 0);
    // Write your code here
}

/*
Maximal square
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
*/

int maxsq(vector<vector<char>> &matrix, int i, int j, int &maxi)
{
    if (i >= matrix.size() || j >= matrix[0].size())
    {
        return 0;
    }
    int right = maxsq(matrix, i + 1, j, maxi);
    int down = maxsq(matrix, i, j + 1, maxi);
    int dig = maxsq(matrix, i + 1, j + 1, maxi);

    if (matrix[i][j] == '1')
    {
        int ans = 1 + min({right, down, dig});
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        return 0;
    }
}
int memmaxsq(vector<vector<char>> &matrix, int i, int j, int &maxi, vector<vector<int>> &dp)
{
    if (i >= matrix.size() || j >= matrix[0].size())
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {

        return dp[i][j];
    }
    int right = memmaxsq(matrix, i + 1, j, maxi, dp);
    int down = memmaxsq(matrix, i, j + 1, maxi, dp);
    int dig = memmaxsq(matrix, i + 1, j + 1, maxi, dp);

    if (matrix[i][j] == '1')
    {
        int ans = 1 + min({right, down, dig});
        maxi = max(maxi, ans);
        dp[i][j] = ans;
        return ans;
    }
    else
    {
        dp[i][j] = 0;
        return 0;
    }
}
int maximalSquare(vector<vector<char>> &matrix)
{
    int col = matrix.size() - 1;
    int row = matrix[0].size() - 1;
    vector<vector<int>> dpmxisq(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
    int maxi = 0;
    for (int c = col; c >= 0; c--)
    {
        for (int r = row; r >= 0; r--)
        {
            int right = 0;
            int down = 0;
            int dig = 0;
            if (c + 1 < matrix.size() && r < matrix[0].size())
                right = dpmxisq[c + 1][r];
            if (c < matrix.size() && r + 1 < matrix[0].size())
                down = dpmxisq[c][r + 1];
            if (c + 1 < matrix.size() && r + 1 < matrix[0].size())
                dig = dpmxisq[c + 1][r + 1];

            if (matrix[c][r] == '1')
            {
                dpmxisq[c][r] = 1 + min({right, down, dig});
                maxi = max(maxi, dpmxisq[c][r]);
            }
        }
    }

    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
    // int maxi = 0;
    // memmaxsq(matrix,0, 0, maxi, dp);
    return maxi * maxi;

    // return maxsq(matrix, 0, 0, maxi);
}

/*
You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.

Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no other shapes other than triangles are allowed in the division. This process will result in n - 2 triangles.

You will triangulate the polygon. For each triangle, the weight of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these weights over all n - 2 triangles.

Return the minimum possible score that you can achieve with some triangulation of the polygon.
*/
int solmst(vector<int> &values,int l,int h)
{
    // base case
    if(l+1==h) return 0;
    int mini=INT_MAX;

    for(int i=l+1;i<h;i++)
    {
        int ans=values[l]*values[i]*values[h] +solmst(values,l,i)+solmst(values,i,h);
        mini=min(mini,ans);
    }
    return mini;
}
int memsolmst(vector<int> &values,int l,int h,vector< vector<int> > &dp)
{
    if(l+1==h) return 0;
    int mini=INT_MAX;

    if(dp[l][h]!=-1) return dp[l][h];
    for(int i=l+1;i<=h;i++)
    {
        int ans=values[l]*values[i]*values[h] +memsolmst(values,i,h,dp)+ memsolmst(values,l,i,dp);
        mini=min(mini,ans);
        dp[l][h]=mini;
    }
    return dp[l][h];

}


int minScoreTriangulation(vector<int> &values)
{
    
    int n=values.size();
    int h=n-1;
    vector<vector<int> > dp2(n,vector<int>(n,0));
    vector< vector<int> > dp(values.size(),vector<int> (n,-1));
    for(int l=n-1;l>=0;l--)
    {
        int mini=INT_MAX;
        for(int i=l;i<n-1;i++)
        {
            mini=min(mini,values[l]*values[i]*values[n-1]+dp2[l][i]+dp2[i][h]);
        }
        dp[l][h]=mini;
    }
    return dp[0][h];
    //return solmst(values,0,values.size()-1);
    return memsolmst(values,0,n-1,dp);
}

//
int fib(int n)
{
    // base case
    if (n == 1)
    {
        arr[1] = 1;
        return arr[1];
    }
    if (n == 0)
    {
        arr[0] = 0;
    }
    if (arr[n] != -1)
    {
        return arr[n];
    }
    return fib(n - 1) + fib(n - 2);
}

int solvere(vector<int> &arr, int x)
{
    if (x == 0)
    {
        return 0;
    }
    if (x < 0)
    {
        return INT_MAX;
    }
    int minc = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {

        int ans = solvere(arr, x - arr[i]);
        if (ans != INT_MAX)
        {
            minc = min(minc, ans + 1);
        }
    }
    return minc;
}

int kthGrammar(int n, int k)
{
    string st = "0";
    st = "0";
    for (int i = 2; i < n; i++)
    {
        string t = "";
        for (int ki = 0; ki <= st.size() / 2; ki++)
        {
            if (st[ki] == '0')
            {
                t = t + "01";
            }
            else
            {
                t = t + "10";
            }
        }
        st = t;
    }
    if (k - 1 >= n / 2)
    {
        if (st[k - 1] == '0')
        {
            return 1;
        }
        else
            return 0;
    }
    char ans = st[k - 1];
    return ans - '0';
}
int main()
{

    return 0;
}