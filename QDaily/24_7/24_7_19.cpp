class Solution {
public:
    int minimumLevels(vector<int>& p) {
        int cnt = 0, n = p.size(), ans, l = 0;
        for(auto i: p) if(i) ++cnt; cnt -= n - cnt;
        for(ans = 0; ans < n; ++ans) {
            if(p[ans]) ++l; else --l;
            if(l << 1 > cnt) return ans == n - 1 ? -1 : ans + 1;
        }
        return -1;
    }
};
static auto _ = []() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    return 0;
}();