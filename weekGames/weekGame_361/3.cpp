class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        int n = nums.size();
        vector<int> cnt(n + 1);
        cnt[0] = 1;
        long long ans = 0;
        int s = 0;
        for (int x: nums) {
            if (x % mod == k)
                s = (s + 1) % mod;
            int s2 = (s - k + mod) % mod;
            if (s2 <= n)
                ans += cnt[s2];
            cnt[s]++;
        }
        return ans;
    }
};