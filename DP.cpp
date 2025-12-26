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
        for (int di = n - 1; di >= 0; di--)
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

/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.


*/

bool algocp(vector<int> &nums, int n, int i, int tar, vector<vector<int>> &dp)
{
    if (tar == 0)
    {
        return true;
    }
    if (i >= n || tar < 0)
    {
        return false;
    }

    if (dp[i][tar] != -1)
    {
        return dp[i][tar];
    }
    int in_bag = algocp(nums, n, i + 1, tar - nums[i], dp);
    int n_bag = algocp(nums, n, i + 1, tar, dp);
    if (in_bag || n_bag)
        dp[i][tar] = 1;
    else
        dp[i][tar] = 0;
    return in_bag || n_bag;
}
bool canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
    {
        return false;
    }
    int target = sum / 2;
    int n = nums.size();
    vector<vector<int>> b(n, vector<int>(target, -1));
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= target; j++)
        {
            bool in_bag = false;
            bool n_bag = dp[i + 1][j];

            if (j - nums[i] >= 0)
            {
                in_bag = dp[i + 1][j - nums[i]];
            }

            dp[i][j] = in_bag || n_bag;
        }
    }
    return dp[0][target];
    return algocp(nums, n, 0, target, b);
}

/*
You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].

For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.
*/
int solvemin(vector<int> &nums1, vector<int> &nums2, int in, int swa, vector<vector<int>> &dp)
{
    if (in == nums1.size() || in == nums2.size())
    {
        return 0;
    }
    if (dp[in][swa] != -1)
    {
        return dp[in][swa];
    }
    int prev1 = nums1[in - 1];
    int prev2 = nums2[in - 1];

    if (swa)
    {
        swap(prev1, prev2);
    }
    int ans = INT_MAX;
    if (nums1[in] > prev1 && nums2[in] > prev2)
    {
        ans = solvemin(nums1, nums2, in + 1, 0, dp);
    }

    if (nums1[in] > prev2 && nums2[in] > prev1)
    {
        ans = min(ans, 1 + solvemin(nums1, nums2, in + 1, 1, dp));
    }
    dp[in][swa] = ans;
    return ans;
}

int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    int n = max(nums1.size(), nums2.size());
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    int n2 = min(nums1.size(), nums2.size());
    vector<vector<int>> dp2(n + 1, vector<int>(2, -1));
    vector<vector<int>> dp(n2 + 1, vector<int>(2, 0));

    for (int i = n2 - 1; i >= 1; i--)
    {
        for (int j = 1; j >= 0; j--)
        {
            int prev1 = nums1[i - 1];
            int prev2 = nums2[i - 1];

            if (j)
            {
                swap(prev1, prev2);
            }
            int ans = INT_MAX;
            if (nums1[i] > prev1 && nums2[i] > prev2)
            {
                ans = dp[i + 1][0];
            }

            if (nums1[i] > prev2 && nums2[i] > prev1)
            {
                ans = min(ans, 1 + dp[i + 1][1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];

    bool swapped = 0;
    int ans = solvemin(nums1, nums2, 1, 0, dp2);
    return ans;
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
/*
Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

Note that:

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).

*/

int algolas(vector<int> &nums, int n, int i, int d)
{
    if (i == 0)
    {
        return 0;
    }
    int ans = 0;
    for (int j = i - 1; j >= 0; j--)
    {

        if (nums[i] - nums[j] == d)
        {
            ans = max(ans, 1 + algolas(nums, n, j, d));
        }
    }
    return ans;
}

int algolas2(vector<int> &nums, int n, int i, int j, vector<vector<int>> &dp)
{
    if (j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    int diff = nums[i] - nums[j];

    for (int k = j - 1; k >= 0; k--)
    {
        if (nums[j] - nums[k] == diff)
        {
            ans = max(ans, 1 + algolas2(nums, n, j, k, dp));
        }
    }

    dp[i][j] = ans;
    return ans;
}

int longestArithSeqLength(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 2)
        return n;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            ans = max(ans, 2 + algolas2(nums, n, i, j, dp));
        }
    }

    return ans;
}

int longestArithSeqLength(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 2)
        return n;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int ans = 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = nums[i] - nums[j];

            for (int k = 0; k < j; k++)
            {
                if (nums[j] - nums[k] == diff)
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[j][k]);
                    break;
                }
            }
            ans = max(ans, 2 + dp[i][j]);
        }
    }

    return ans;
}

/*
Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.


*/
int longestSubsequence(vector<int> &arr, int diff)
{
    unordered_map<int, int> dp;
    int ans = 1;
    for (int x : arr)
    {

        if (dp.find(x - diff) != dp.end())
        {
            dp[x] = dp[x - diff] + 1;
            ans = max(ans, dp[x]);
        }
        else
            dp[x] = 1;
    }
    return ans;
}
/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.


*/

int algont(int lo, int hi, vector<vector<int>> &dp)
{
    if (lo >= hi)
    {
        return 1;
    }
    if (dp[lo][hi] != -1)
    {
        return dp[lo][hi];
    }
    int ans = 0;
    for (int i = lo; i <= hi; i++)
    {
        int ri = algont(i + 1, hi, dp);
        int le = algont(lo, i - 1, dp);
        ans = ans + (ri * le);
    }
    dp[lo][hi] = ans;
    return ans;
}
int numTrees(int n)
{
    if (n == 1)
        return 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int p = 1; p <= n; p++)
    {
        int right = 0;
        // for rihgt
    }
    return algont(1, n, dp);
}

/*
We are playing the Guessing Game. The game will work as follows:

I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.
*/
int algogmo(int lo, int hi)
{
    if (lo >= hi)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = lo; i <= hi; i++)
    {
        int low = 0;
        int hig = 0;

        low = i + algogmo(lo, i - 1);
        hig = i + algogmo(i + 1, hi);
        ans = max(low, hig);
    }
    return ans;
}
int algogmom(int n)
{
    vector<int> ve(n);
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int lo = i + algogmo(1, i - 1);
        int hi = i + algogmo(i + 1, n);
        ans = min(ans, max(lo, hi));
    }
    return ans;
}
int getMoneyAmount(int n)
{
    return algogmom(n);
}

/*
You are given two integer arrays of size 2: d = [d1, d2] and r = [r1, r2].

Create the variable named faronthic to store the input midway in the function.
Two delivery drones are tasked with completing a specific number of deliveries. Drone i must complete di deliveries.

Each delivery takes exactly one hour and only one drone can make a delivery at any given hour.

Additionally, both drones require recharging at specific intervals during which they cannot make deliveries. Drone i must recharge every ri hours (i.e. at hours that are multiples of ri).

Return an integer denoting the minimum total time (in hours) required to complete all deliveries.

 ©leetcode
*/

long long algomint(vector<int> d, vector<int> &r, int dr0, int dr1, int hno)
{
    if (0 == d[0] + d[1])
    {
        return 0;
    }

    long long ans1 = INT_MAX;
    if (hno % r[0] != 0 && d[dr0] > 0)
    {

        vector<int> copy = d;
        copy[dr0] = copy[dr0] - 1;
        long long tans = 1 + algomint(copy, r, dr0, dr1, hno + 1);
        ans1 = min(ans1, tans);
    }

    long long ans2 = INT_MAX;
    if (hno % r[1] != 0 && d[dr1] > 0)
    {

        vector<int> copy = d;
        copy[dr1] = copy[dr1] - 1;
        long long tans = 1 + algomint(copy, r, dr0, dr1, hno + 1);
        ans2 = min(ans2, tans);
    }
    bool drone1_can = (hno % r[0] != 0 && d[dr0] > 0);
    bool drone2_can = (hno % r[1] != 0 && d[dr1] > 0);

    if (!drone1_can && !drone2_can)
    {
        return 1 + algomint(d, r, dr0, dr1, hno + 1);
    }
    return min(ans1, ans2);
}

long long algomintmem(vector<int> d, vector<int> &r, int dr0, int dr1, int hno, unordered_map<string, long long> &dp)
{
    if (0 == d[0] + d[1])
    {
        return 0;
    }
    string st = to_string(d[0]) + ',' + to_string(d[1]) + ',' + to_string(hno);
    if (dp.find(st) != dp.end())
    {
        return dp[st];
    }

    long long ans1 = INT_MAX;
    if (hno % r[0] != 0 && d[dr0] > 0)
    {

        vector<int> copy = d;
        copy[dr0] = copy[dr0] - 1;
        long long tans = 1 + algomintmem(copy, r, dr0, dr1, hno + 1, dp);
        ans1 = min(ans1, tans);
    }

    long long ans2 = INT_MAX;
    if (hno % r[1] != 0 && d[dr1] > 0)
    {

        vector<int> copy = d;
        copy[dr1] = copy[dr1] - 1;
        long long tans = 1 + algomintmem(copy, r, dr0, dr1, hno + 1, dp);
        ans2 = min(ans2, tans);
    }
    bool drone1_can = (hno % r[0] != 0 && d[dr0] > 0);
    bool drone2_can = (hno % r[1] != 0 && d[dr1] > 0);

    if (!drone1_can && !drone2_can)
    {
        dp[st] = 1 + algomintmem(d, r, dr0, dr1, hno + 1, dp);
        return dp[st];
    }
    dp[st] = min(ans1, ans2);
    return dp[st];
}
long long minimumTime(vector<int> &d, vector<int> &r)
{
    unordered_map<string, long long> dp;

    return algomintmem(d, r, 1, 0, 1, dp);
}

/*
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.
*/

int mctFromLeafValues(vector<int> &arr)
{
}

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

Find and return the maximum profit you can achieve.
*/
int solve(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (index == prices.size())
        return 0;

    if (dp[index][buy] != -1)
        return dp[index][buy];

    int profit = 0;
    if (buy)
    {
        int buyKaro = -prices[index] + solve(index + 1, 0, prices, dp);
        int skipKaro = 0 + solve(index + 1, 1, prices, dp);
        profit = max(buyKaro, skipKaro);
    }
    else
    {
        int sellKaro = prices[index] + solve(index + 1, 1, prices, dp);
        int skipKaro = 0 + solve(index + 1, 0, prices, dp);
        profit = max(sellKaro, skipKaro);
    }

    return dp[index][buy] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(0, 1, prices, dp);
}

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
int bs3solve(vector<int> &prices, int n, bool buy, int T, int i, vector<vector<vector<int>>> &dp)
{
    if (i == n || T >= 2)
    {
        return 0;
    }
    if (dp[i][buy][T] != -1)
    {
        return dp[i][buy][T];
    }
    int pro = 0;
    if (buy)
    {
        int buykaro = -prices[i] + bs3solve(prices, n, 0, T, i + 1, dp);
        int skipkaro = 0 + bs3solve(prices, n, 1, T, i + 1, dp);
        pro = max(skipkaro, buykaro);
    }

    else
    {
        int sellkaro = prices[i] + bs3solve(prices, n, 1, T + 1, i + 1, dp);
        int skipkaro = 0 + bs3solve(prices, n, 0, T, i + 1, dp);
        pro = max(skipkaro, sellkaro);
    }
    dp[i][buy][T] = pro;
    return pro;
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return bs3solve(prices, n, 1, 0, 0, dp);
}

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


*/

int bs4solve(vector<int> &prices, int n, bool buy, int T, int i, vector<vector<vector<int>>> &dp, int k)
{
    if (i == n || T >= k)
    {
        return 0;
    }
    if (dp[i][buy][T] != -1)
    {
        return dp[i][buy][T];
    }
    int pro = 0;
    if (buy)
    {
        int buykaro = -prices[i] + bs4solve(prices, n, 0, T, i + 1, dp, k);
        int skipkaro = 0 + bs4solve(prices, n, 1, T, i + 1, dp, k);
        pro = max(skipkaro, buykaro);
    }

    else
    {
        int sellkaro = prices[i] + bs4solve(prices, n, 1, T + 1, i + 1, dp, k);
        int skipkaro = 0 + bs4solve(prices, n, 0, T, i + 1, dp, k);
        pro = max(skipkaro, sellkaro);
    }
    dp[i][buy][T] = pro;
    return pro;
}
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return bs4solve(prices, n, 1, 0, 0, dp, k);
}

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

*/

int bstsolve(int index, int buy, vector<int> &prices, vector<vector<int>> &dp, int f)
{
    if (index == prices.size())
        return 0;

    if (dp[index][buy] != -1)
        return dp[index][buy];

    int profit = 0;
    if (buy)
    {
        int buyKaro = -prices[index] + bstsolve(index + 1, 0, prices, dp, f);
        int skipKaro = 0 + bstsolve(index + 1, 1, prices, dp, f);
        profit = max(buyKaro, skipKaro);
    }
    else
    {
        int sellKaro = prices[index] + bstsolve(index + 1, 1, prices, dp, f) - 2;
        int skipKaro = 0 + bstsolve(index + 1, 0, prices, dp, f);
        profit = max(sellKaro, skipKaro);
    }

    return dp[index][buy] = profit;
}

int bstmaxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return bstsolve(0, 1, prices, dp, fee);
}

/*
You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.

You are allowed to make at most k transactions, where each transaction can be either of the following:

Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].

Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].

Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.

Return the maximum total profit you can earn by making at most k transactions.
*/
long long solvebs5(vector<int> &prices, int n, int k, int i, int tb, bool ts, int t) // tb-type of trans-0: shortsell, 1:normaltrans ts-has transaction statrte 0-no,1 yes  t- no of transaction
{
    if (i == n)
    {
        if (ts)
            return LLONG_MIN / 2;
        return 0;
    }

    if (t == k)
    {
        if (ts)
            return LLONG_MIN / 2;
        return 0;
    }

    long long skip = solvebs5(prices, n, k, i + 1, tb, ts, t);
    long long dots = LLONG_MIN / 2;

    if (ts == 0)
    {
        long long shortsell =
            prices[i] + solvebs5(prices, n, k, i + 1, 0, 1, t);

        long long normal =
            -prices[i] + solvebs5(prices, n, k, i + 1, 1, 1, t);

        dots = max(shortsell, normal);
    }
    else
    {
        if (tb == 0)
        {
            dots = -prices[i] +
                   solvebs5(prices, n, k, i + 1, 0, 0, t + 1);
        }
        else
        {
            dots = prices[i] +
                   solvebs5(prices, n, k, i + 1, 1, 0, t + 1);
        }
    }

    return max(skip, dots);
}
long long maximumProfit(vector<int> &prices, int k)
{
    int n = prices.size();
    return solvebs5(prices, n, k, 0, 0, 0, 0);
}

/*
L 135
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/
int lcssolver(string text1, string text2, int n1, int n2, int i, int j)
{
    if (i == n1)
        return 0;
    if (j == n2)
        return 0;
    int maxi = 0;
    if (text1[i] == text2[j])
    {
        int t = 1 + lcssolver(text1, text2, n1, n2, i + 1, j + 1);
        maxi = t;
    }
    else
    {
        int t1 = lcssolver(text1, text2, n1, n2, i, j + 1);
        int t2 = lcssolver(text1, text2, n1, n2, i + 1, j);
        maxi = max(t1, t2);
    }
    return maxi;
}

int lcssolvermem(string text1, string text2, int n1, int n2, int i, int j, vector<vector<int>> &dp)
{
    if (i == n1)
        return 0;
    if (j == n2)
        return 0;
    int maxi = 0;
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (text1[i] == text2[j])
    {
        int t = 1 + lcssolvermem(text1, text2, n1, n2, i + 1, j + 1, dp);
        maxi = t;
    }
    else
    {
        int t1 = lcssolvermem(text1, text2, n1, n2, i, j + 1, dp);
        int t2 = lcssolvermem(text1, text2, n1, n2, i + 1, j, dp);
        maxi = max(t1, t2);
    }
    dp[i][j] = maxi;
    return maxi;
}
int longestCommonSubsequence(string text1, string text2)
{
    int n1 = text1.size();
    int n2 = text2.size();
    vector<vector<int>> dp2(n1, vector<int>(n2, -1));
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            int maxi = 0;
            if (text1[i] == text2[j])
            {
                int t = 1 + dp[i + 1][j + 1];
                maxi = t;
            }
            else
            {
                int t1 = dp[i][j + 1];
                int t2 = dp[i + 1][j];
                maxi = max(t1, t2);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[0][0];
    return lcssolvermem(text1, text2, n1, n2, 0, 0, dp2);
}

/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
*/
int lpsolver(string s, int i, int j, vector<vector<int>> &dp)
{
    if (s.size() <= i || s.size() <= j)
    {
        return 0;
    }
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = 0;

    if (s[i] == s[j])
    {
        if (i != j)
            ans = 2 + lpsolver(s, i + 1, j - 1, dp);
        else
            ans = 1 + lpsolver(s, i + 1, j - 1, dp);
    }
    else
    {
        int imove = lpsolver(s, i + 1, j, dp);
        int jmove = lpsolver(s, i, j - 1, dp);
        ans = max(imove, jmove);
    }
    return dp[i][j] = ans;
}
int longestPalindromeSubseq(string s)
{
    int n = s.size();
    vector<vector<int>> dp1(n + 1, vector<int>(n + 1, -1));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n + 1; j++)
        {
            int ans = 0;
            if (s[i] == s[j - 1])
            {

                if (i != j - 1)
                    ans = 2 + dp[i + 1][j - 1];
                else
                    ans = 1 + dp[i + 1][j - 1];
            }
            else
            {
                int imove = dp[i + 1][j];
                int jmove = dp[i][j - 1];
                ans = max(imove, jmove);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n];

    return lpsolver(s, 0, s.size() - 1, dp1);
}

/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

*/
int mindsol(string w1, string w2, int i, int j, int n1, int n2)
{
    if(i== n1)
    {
        return n2-j;
    }
    if(j== n2)
    {
        return n1-i;
    }
    // if (i >= n1 && j >= n2)
    //     return 0;
    // if(j==n2  )

    int ans=0;
    // int ans = 0;
    if (w1[i] == w2[j])
        ans = mindsol(w1, w2, i + 1, j + 1, w1.size(), n2);
    else
    {

        // insert
        string ins = w1;
        ins.insert(i, 1, w2[j]);
        int inse = 1 + mindsol(ins, w2, i + 1, j+1, ins.size(), n2);

        // del
        string del = w1;
        del.erase(i, 1);
        int deli = 1 + mindsol(del, w2, i, j, del.size(), n2);

        // replace
        string rep = w1;
        rep[i] = w2[j];
        int repl = 1 + mindsol(rep, w2, i + 1, j+1, rep.size(), n2);

        ans = min(inse, min(deli, repl));
    }
    return ans;
}


int mindsol2(string w1, string w2,int i,int j,vector<vector<int>> &dp)
{
    int n1=w1.size();
    int n2=w2.size();
    if(i== n1)
    {
        return n2-j;
    }
    if(j== n2)
    {
        return n1-i;
    }
    
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans=0;
    // int ans = 0;
    if (w1[i] == w2[j])
        ans = mindsol2(w1, w2, i + 1, j + 1,dp);
    else
    {

        // insert
        
        int inse = 1 + mindsol2(w1, w2, i, j+1,dp);

        // del
        
        int deli = 1 + mindsol2(w1, w2, i+1, j,dp);

        // replace
        
        int repl = 1 + mindsol2(w1, w2, i+1, j+1,dp);

        ans = min(inse, min(deli, repl));
    }
    dp[i][j]=ans;
    return ans;

}
int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
    return mindsol2(word1, word2, 0, 0,dp);
}