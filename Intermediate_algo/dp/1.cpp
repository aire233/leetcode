class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dp = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if (i > dp) return false;
            dp = max(dp, i + nums[i]);
        }
        return true;
    }
};