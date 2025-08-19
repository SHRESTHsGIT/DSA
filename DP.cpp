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
int solmst(vector<int> &values, int l, int h)
{
    // base case
    if (l + 1 == h)
        return 0;
    int mini = INT_MAX;

    for (int i = l + 1; i < h; i++)
    {
        int ans = values[l] * values[i] * values[h] + solmst(values, l, i) + solmst(values, i, h);
        mini = min(mini, ans);
    }
    return mini;
}
int memsolmst(vector<int> &values, int l, int h, vector<vector<int>> &dp)
{
    if (l + 1 == h)
        return 0;
    int mini = INT_MAX;

    if (dp[l][h] != -1)
        return dp[l][h];
    for (int i = l + 1; i <= h; i++)
    {
        int ans = values[l] * values[i] * values[h] + memsolmst(values, i, h, dp) + memsolmst(values, l, i, dp);
        mini = min(mini, ans);
        dp[l][h] = mini;
    }
    return dp[l][h];
}

int minScoreTriangulation(vector<int> &values)
{

    int n = values.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> dp2(values.size(), vector<int>(n, -1));
    for (int l = n - 1; l >= 0; l--)
    {

        for (int h = l + 2; h < n; h++)
        {
            int mini = INT_MAX;
            for (int i = l + 1; i < h; i++)
            {
                int ans = values[l] * values[i] * values[h] + dp[i][h] + dp[l][i];
                mini = min(mini, ans);
            }
            dp[l][h] = mini;
        }
    }
    return dp[0][n - 1];
    // return solmst(values,0,values.size()-1);
    // return memsolmst(values,0,n-1,dp2);
}
/*
There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles along the way.

You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.

For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane.

For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.

Note: There will be no obstacles on points 0 and n.
*/
int solminside(vector<int> &obs, int i, int pos)
{
    if (i == obs.size() - 1)
        return 0;

    int mini = INT_MAX;
    for (int k = 1; k <= 3; k++)
    {
        int ans = INT_MAX;
        if (obs[i + 1] != k)
        {
            if (pos == k)
            {
                ans = solminside(obs, i + 1, k);
            }
            else
            {
                if (obs[i] != k)
                    ans = 1 + solminside(obs, i + 1, k);
            }
        }
        mini = min(mini, ans);
    }

    return mini;
}

int solminsidemem(vector<int> &obs, int i, int pos, vector<vector<int>> &dp)
{

    if (i == obs.size() - 1)
        return 0;
    if (dp[i][pos] != -1)
        return dp[i][pos];
    int mini = INT_MAX;
    for (int k = 1; k <= 3; k++)
    {
        int ans = INT_MAX;
        if (obs[i + 1] != k)
        {
            if (pos == k)
            {
                ans = solminsidemem(obs, i + 1, k, dp);
            }
            else
            {
                if (obs[i] != k)
                    ans = 1 + solminsidemem(obs, i + 1, k, dp);
            }
        }
        mini = min(mini, ans);
    }
    dp[i][pos] = mini;
    return mini;
}
int minSideJumps(vector<int> &obstacles)
{
    int ans = 0;
    int n = obstacles.size();
    vector<vector<int>> dp2(n, vector<int>(3, -1));
    vector<vector<int>> dp(n, vector<int>(3, 0));
    for (int i = 0; i < 3; i++)
    {
        if (obstacles[n - 1] == i + 1)
            dp[n - 1][i] = INT_MAX;
    }

    for (int i = n - 2; i >= 0; i--)
    {

        for (int pos = 1; pos <= 3; pos++) // i par pos
        {
            if (obstacles[i] == pos)
            {
                dp[i][pos - 1] = INT_MAX;
                continue;
            }
            int mini = INT_MAX;
            for (int k = 1; k <= 3; k++) // i+1 par pos
            {
                int ans = INT_MAX;
                if (obstacles[i + 1] != k)
                {
                    if (pos == k)
                    {
                        ans = dp[i + 1][k - 1];
                    }
                    else
                    {
                        if (obstacles[i] != k)
                            if (dp[i + 1][k - 1] != INT_MAX)
                                ans = 1 + dp[i + 1][k - 1];
                    }
                }
                mini = min(mini, ans);
            }
            dp[i][pos - 1] = mini;
        }
    }

    // ans = solminsidemem(obstacles, 0, 2, dp2);
    // ans = solminside(obstacles, 0, 2);
    // if (ans == INT_MAX)
    //     return 0;
    // return ans;
    return dp[0][1];
}
/*
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.
*/
int msatfolve(vector<int> &sat, int i, int vno, vector<vector<int>> &dp)
{
    if (sat.size() == i)
    {
        return 0;
    }
    if (dp[i][vno] != -1)
        return dp[i][vno];
    int inclu = (vno + 1) * sat[i] + msatfolve(sat, i + 1, vno + 1, dp);
    int exclu = msatfolve(sat, i + 1, vno, dp);
    dp[i][vno] = max(inclu, exclu);
    return dp[i][vno];
}
int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    vector<vector<int>> dp1(n, vector<int>(n + 1, -1));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int vno = i; vno >= 0; vno--)
        {

            int inclu = (vno + 1) * satisfaction[i] + dp[i + 1][vno + 1];
            int exclu = dp[i + 1][vno];
            dp[i][vno] = max(inclu, exclu);
        }
    }

    // int ans = msatfolve(satisfaction, 0, 0, dp1);
    //  for(int i=0;i<n+1;i++)
    //  {
    //      for(int j=0;j<n+1;j++)
    //      {
    //          cout<<dp1[i][j]<<',';
    //      }
    //      cout<<"\n";
    //  }
    return dp[0][0];
}
/*
Longest increasing subsequence-Given an integer array nums, return the length of the longest strictly increasing subsequence.
*/
int sollol(vector<int> &num, int i, int prev, vector<vector<int>> &dp)
{
    if (i == num.size())
    {
        return 0;
    }

    if (dp[i][prev + 1] != -1)
    {
        return dp[i][prev + 1];
    }
    int inclu = 0;
    if (prev == -1 || num[prev] < num[i])
    {
        inclu = 1 + sollol(num, i + 1, i, dp);
    }

    int exclu = sollol(num, i + 1, prev, dp);
    dp[i][prev + 1] = max(inclu, exclu);
    return dp[i][prev + 1];
}
int lengthOfLIS(vector<int> &num)
{
    int n = num.size();
    vector<vector<int>> dp1(n + 1, vector<int>(n + 1, -1));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = i - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || num[i] > num[prev])
            {
                include = 1 + dp[i + 1][i + 1];
            }
            int exclude = dp[i + 1][prev + 1];
            dp[i][prev + 1] = max(include, exclude);
        }
    }
    return dp[0][0];
    int ans = sollol(num, 0, -1, dp1);
    return ans;
}
/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

*/

int maxEnvelopes(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b)
         {
                 if (a[0] != b[0])
                     return a[0] < b[0];
                 else
                     return a[1] > b[1]; });

    vector<int> req(n);
    for (int i = 0; i < n; i++)
    {
        req[i] = arr[i][1];
    }

    vector<int> lis;
    for (int i = 0; i < req.size(); i++)
    {
        int h = req[i];
        int pos = lower_bound(req.begin(), req.end(), req[i]) - req.begin();

        if (pos == lis.size())
        {
            lis.push_back(h);
        }
        else
        {
            lis[pos] = h;
        }
    }

    return lis.size();
}
//
/*
There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.
*/

int algo(int in, int hi, vector<int> &A, int n, vector<vector<int>> &dp)
{
    if (n == 0 || in > hi)
    {
        return 0;
    }
    if (dp[in][n] != -1)
    {
        return dp[in][n];
    }
    int taken = A[in] + algo(in + 2, hi, A, n - 1, dp);
    int nottaken = 0 + algo(in + 1, hi, A, n, dp);
    dp[in][n] = max(taken, nottaken);
    return dp[in][n];
}

int maxSizeSlices(vector<int> &slices)
{
    // vector<vector<int>> dp(slices.size() + 1, vector<int>(slices.size() + 1, -1));
    // int n = slices.size();
    // vector<bool> B(n, false);
    // int taken = 0;
    // int ans = algo(slices, B, 0, dp);
    // return ans;
    int n = slices.size();
    vector<vector<int>> b(n, vector<int>(n, -1));
    vector<vector<int>> B(n, vector<int>(n, -1));
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int in = n - 2; in >= 0; in--)
    {
        for (int tn = 0; tn < n / 3; tn++)
        {
            int taken = slices[in] + dp[in + 2][tn - 1];
            int ntaken = 0 + dp[in + 1][tn];
            dp[in][tn] = max(taken, ntaken);
        }
    }
    vector<vector<int>> dp2(n + 2, vector<int>(n + 2, 0));
    int cc1 = dp[0][n / 3];
    for (int in = n - 1; in >= 1; in--)
    {
        for (int tn = 0; tn < n / 3; tn++)
        {
            int taken = slices[in] + dp2[in + 2][tn - 1];
            int ntaken = 0 + dp2[in + 1][tn];
            dp2[in][tn] = max(taken, ntaken);
        }
    }

    int cc2 = dp2[1][n / 3];
    return max(cc2, cc1);
    int c1 = algo(0, n - 2, slices, n / 3, B);
    int c2 = algo(1, n - 1, slices, n / 3, b);
    return max(c1, c2);
    int k = n / 3;
}
/*
You have n dice, and each dice has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.


*/
int nrtalgo(int n, int k, int t, int di, vector<vector<int>> &dp)
{
    if (t == 0 && di == n)
    {
        return 1;
    }
    if (di > n)
    {
        return 0;
    }
    if (t <= 0)
    {
        return 0;
    }
    if (dp[t][di] != -1)
    {
        return dp[t][di];
    }
    long long sum = 0;
    for (int i = 1; i <= k; i++)
    {
        int re = nrtalgo(n, k, t - i, di + 1, dp);
        sum = sum + re;
    }
    const int MOD = 1000000007;
    dp[t][di] = sum % MOD;
    return dp[t][di];
}
int numRollsToTarget(int n, int k, int target)
{
    vector<vector<int>> b(target + 1, vector<int>(n + 1, -1));
    vector<vector<int>> dp(target + 1, vector<int>(n + 1, 0));
    dp[0][n] = 1;
    for (int t = 0; t <= target; t++)
    {
        for (int di = n-1; di >= 0; di--)
        {
            long long sum = 0;
            for (int i = 1; i <= k; i++)
            
            {
                if (t - i < 0 || di + 1 > n)
                    break;
                sum = sum + dp[t - i][di + 1];
            }
            const int MOD = 1000000007;
            dp[t][di] = sum % MOD;
        }
    }
    return dp[target][0];
    return nrtalgo(n, k, target, 0, b);
}

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