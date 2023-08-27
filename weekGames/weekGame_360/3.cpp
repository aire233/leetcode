class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        if(accumulate(nums.begin(), nums.end(), 0LL) < target) return -1;
        long long cnt[31] = {0}, s = 0;
        for(auto &x: nums) cnt[__builtin_ctz(x)]++;
        int i = 0, ans = 0;
        while(1LL << i <= target)
        {
            if((s += cnt[i] << i) >= (target & (1LL << ++i) - 1))continue;
            for(ans++;!cnt[i];i++)ans++;
        }
        return ans;
    }
};