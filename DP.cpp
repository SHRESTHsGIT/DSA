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
    int inclu = nums[i] + solvemem(nums, i + 2,dp);
   
    int exclu = solvemem(nums, i + 1,dp);
    dp[i]=max(inclu,exclu);
    return dp[i];
}
int solvetab(vector<int> &nums)
{
    vector<int> dp(nums.size(),0);
    dp[0]=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        int inclu=nums[i]+dp[i-2];
        int exclu=0+dp[i-1];
        dp[i]=max(inclu,exclu);
    }
    return dp[nums.size()-1];
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    //return solvere3(nums, 0);
    // Write your code here.
    
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
int main()
{

    return 0;
}