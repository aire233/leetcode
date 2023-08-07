class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0], dp = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < min) min = prices[i];
            dp = max(dp, prices[i] - min);
        }
        return dp;
    }
};