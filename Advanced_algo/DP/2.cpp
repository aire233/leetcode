class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), dp[3][2], ans = -1;
        memset(dp, 0, sizeof(dp));
        dp[0][1] = -prices[0];
        for(int i = 0; i < n; i++)
        {
            dp[(i+1)%3][0] = max(dp[i%3][0], dp[i%3][1]+prices[i]);
            if(i > 1)
                dp[(i+1)%3][1] = max(dp[i%3][1], dp[(i-1)%3][0]-prices[i]);
            else
                dp[(i+1)%3][1] = max(dp[i%3][1], dp[i%3][0]-prices[i]);
        }
        return dp[n%3][0];
    }
};