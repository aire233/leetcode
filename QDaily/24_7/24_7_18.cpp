class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& es, vector<int>& dr) {
        vector<int64_t> d(n, INT_MAX); d[0] = 0; bool u = 1;
        for (int i = 1; u && (u = 0, i < n); ++i) for (auto& e : es) {
            if (dr[e[0]] > d[e[0]] && d[e[0]] + e[2] < d[e[1]]) d[e[1]] = d[e[0]] + e[2], u = 1;
            if (dr[e[1]] > d[e[1]] && d[e[1]] + e[2] < d[e[0]]) d[e[0]] = d[e[1]] + e[2], u = 1;
        }
        vector<int> ans(n);
        for (int i = 1; i < n; ++i) ans[i] = (d[i] >= dr[i] ? -1 : d[i]);
        return ans;
    }
};
static auto _ = []() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    return 0;
}();
