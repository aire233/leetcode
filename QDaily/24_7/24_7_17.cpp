// 2959

// template for algorithm competitions
// Author: Aire

#include "bits/stdc++.h"
#include <queue>
#define For(i, a, b) for (auto i = a; i < (b); ++i)
#define Rof(i, a, b) for (auto i = a; i > (b); --i)
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
#define LL long long
using namespace std;

template <class A, class B> string to_string(const pair<A, B>& p);
template <class A, class B, class C> string to_string(const tuple<A, B, C>& p);
template <class A, class B, class C, class D>
string to_string(const tuple<A, B, C, D>& p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; }
template <size_t L> string to_string(const bitset<L>& x) {
    return x.to_string();
}
template <class A, class T = typename A::value_type>
string to_string(const A& v) {
    bool first = 1;
    string res = "{";
    for (const auto& x : v) {
        if (!first)
            res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <class A, class B> string to_string(const pair<A, B>& p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class A, class B, class C> string to_string(const tuple<A, B, C>& p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
        to_string(get<2>(p)) + ")";
}
template <class A, class B, class C, class D>
string to_string(const tuple<A, B, C, D>& p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
        to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

#include <iostream>

void debug_out() { std::cerr << std::endl; }
template <class H, class... T> void debug_out(const H& h, const T &...t) {
    std::cerr << " " << to_string(h);
    debug_out(t...);
}
#ifndef ONLINE_JUDGE
#define debug(...)                                                             \
  std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)                                                             \
  if (0)                                                                       \
  std::puts("No effect.")
#endif

class Solution { // O(2^n * n^2 * nlog n)
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(n); // 邻接表表示图
        for (auto& e : roads) {
            int x = e[0], y = e[1], wt = e[2];
            g[x].emplace_back(y, wt);
            g[y].emplace_back(x, wt);
        }

        auto dijkstra = [&](int src, vector<int>& dist, int mask) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            dist.assign(n, INT_MAX / 2);
            dist[src] = 0;
            pq.emplace(0, src);

            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d > dist[u]) continue;
                for (auto& [v, w] : g[u]) {
                    if ((mask >> v) & 1 && dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        pq.emplace(dist[v], v);
                    }
                }
            }
        };

        auto check = [&](int s) -> bool {
            vector<vector<int>> f(n, vector<int>(n, INT_MAX / 2));
            for (int i = 0; i < n; i++) {
                if ((s >> i) & 1) {
                    dijkstra(i, f[i], s);
                }
            }

            for (int i = 0; i < n; i++) {
                if (((s >> i) & 1) == 0) continue;
                for (int j = 0; j < i; j++) {
                    if ((s >> j) & 1 && f[i][j] > maxDistance) {
                        return false;
                    }
                }
            }
            return true;
        };

        int ans = 1;
        for (int s = 1; s < (1 << n); s++) ans += check(s);
        return ans;
    }
};
