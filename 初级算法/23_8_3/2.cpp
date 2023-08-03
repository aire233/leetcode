class Solution {
public:
    int climbStairs(int n) {
        int dp[47] = {0};
        dp[1] = 1;
        for(int i = 2; i <= n + 1; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n + 1];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 0; i < n; i++)
        {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};