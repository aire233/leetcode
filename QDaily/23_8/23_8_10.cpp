#include <bits/stdc++.h>
using namespace std;

#define For(i, a, b) for(int i = a; i < b; i++)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        int ans = INT_MAX;
        For(i, 0, n)
            dp[0][i] = grid[0][i];
        For(i, 1, n)
            For(j,0,n)
            {
                int low = INT_MAX;
                For(k, 0, n)
                {
                    if(j == k) continue;
                    low = min(low, dp[i - 1][k]);
                }
                dp[i][j] = low + grid[i][j];
            }
        For(j, 0, n)
            ans = min(ans, dp[n - 1][j]);
        return ans;
    }
};