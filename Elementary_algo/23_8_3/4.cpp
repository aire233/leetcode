class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[100005] = {0}, ans = nums[0];
        dp [0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            dp[i] = (dp[i - 1] > 0) * dp[i - 1] + nums[i];
            if(ans < dp[i]) ans = dp[i];
        } 
        return ans;
    }
};