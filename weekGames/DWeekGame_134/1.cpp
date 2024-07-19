class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0, n = colors.size();
        for (int i = 1; i < n - 1; ++i) {
            if(colors[i] != colors[i - 1] && colors[i] != colors[i + 1]) ++ans;
        }
        if(colors[0] != colors[1] && colors[0] != colors[n - 1]) ++ans;
        if(colors[n - 1] != colors[0] && colors[n - 1] != colors[n - 2]) ++ans;
        return ans;
    }
};

static auto _ = []() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    return 0;
}();