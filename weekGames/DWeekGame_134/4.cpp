#define LL long long
class Solution {
public:
    LL countSubarrays(vector<int>& nums, int k) {
        LL ans = 0;
        int l = 0, r = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0 && (nums[j] & nums[i]) != nums[j]; nums[j--] &= nums[i]);
            while (l <= i && nums[l] < k) ++l;
            while (r <= i && nums[r] <= k) ++r;
            ans += r - l;
        }
        return ans;
    }
};
static auto _ = []() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    return 0;
}();