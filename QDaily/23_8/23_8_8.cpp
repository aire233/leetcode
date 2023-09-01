class Solution {
public:
    int maxAbsoluteSum(vector<int> &nums) {
        int ans = 0, f_max = 0, f_min = 0;
        for (int x: nums) {
            f_max = max(f_max, 0) + x;
            f_min = min(f_min, 0) + x;
            ans = max(ans, max(f_max, -f_min));
        }
        return ans;
    }
};

class Solution {
public:
    int maxAbsoluteSum(vector<int> &nums) {
        int s = 0, mx = 0, mn = 0;
        for (int x: nums) {
            s += x;
            mx = max(mx, s);
            mn = min(mn, s);
        }
        return mx - mn;
    }
};