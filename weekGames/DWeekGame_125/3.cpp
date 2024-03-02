#include "bits/stdc++.h"
#define rep(i, a, n) for (auto i = a; i <= (n); ++i)
#define revrep(i, a, n) for (auto i = n; i >= (a); --i)
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (b < a) { a = b; return 1; } return 0; }
using namespace std;

template<class A, class B> string to_string(const pair<A, B>& p);
template<class A, class B, class C> string to_string(const tuple<A, B, C>& p);
template<class A, class B, class C, class D> string to_string(const tuple<A, B, C, D>& p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; }
template<size_t L> string to_string(const bitset<L>& x) { return x.to_string(); }
template<class A, class T = typename A::value_type> string to_string(const A& v) {
    bool first = 1;
    string res = "{";
    for (const auto& x : v) {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template<class A, class B> string to_string(const pair<A, B>& p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template<class A, class B, class C> string to_string(const tuple<A, B, C>& p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
template<class A, class B, class C, class D> string to_string(const tuple<A, B, C, D>& p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }
template<class H, class... T> void debug_out(const H& h, const T&... t) {
    cerr << " " << to_string(h);
    debug_out(t...);
}
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) if (0) puts("No effect.")
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = sz(edges) + 1;
        static vector<vector<pii>> g;
        g.assign(n, {});
        for (auto& vec : edges) {
            int x = vec[0];
            int y = vec[1];
            int w = vec[2];
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, w);
        }

        auto dfs = [&](auto& dfs, int now, int fa, int d) -> int {
            int ans = d % signalSpeed == 0;
            for (auto [v, w] : g[now]) if (v != fa) {
                ans += dfs(dfs, v, now, d + w);
            }
            return ans;
        };

        vector<int> ans(n);
        rep(i, 0, n - 1) {
            int sum = 0;
            for (auto [v, w] : g[i]) {
                int c = dfs(dfs, v, i, w);
                ans[i] += sum * c;
                sum += c;
            }
        }
        return ans;
    }
};