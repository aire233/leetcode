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

#define MAXN 105

struct edge {
    int v, w;
};
struct node {
    int dis, u;
    node(int dis, int u) : dis(dis), u(u) {}
    bool operator>(const node& a) const { return dis > a.dis; }
};
class Solution {
private:
    vector<edge> e[MAXN];
    int dis[MAXN], vis[MAXN];

    void dijkstra(int from, int to) {
        priority_queue<node, vector<node>, greater<node>> q;
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        dis[from] = 0;
        q.push(node(0, from));
        while (!q.empty()) {
            node cur = q.top();
            q.pop();
            int u = cur.u;
            if (vis[u])
                continue;
            vis[u] = 1;
            for (auto& i : e[u]) {
                int v = i.v, w = i.w;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push(node(dis[v], v));
                }
            }
        }
    }

    int dfs(int u) {
        vis[u] = 1;
        int res = 1;
        for (auto& i : e[u]) if (!vis[i.v]) res += dfs(i.v);
        return res;
    }

    int solve(int mask, int n, int maxDistance, vector<vector<int>>& roads) {
        For(i, 0, n) e[i].clear();
        for (auto& road : roads) {
            if (mask & (1 << road[0]) && mask & (1 << road[1])) {
                e[road[0]].push_back({road[1], road[2]});
                e[road[1]].push_back({road[0], road[2]});
            }
        }
        For(i, 0, n) For (j, 0, n) if (mask & (1 << i) && mask & (1 << j) && i != j) {
            dijkstra(i, j);
            if (dis[j] > maxDistance) return 0;
        }
        memset(vis, 0, sizeof(vis));
        return dfs(__builtin_ctz(mask)) == __builtin_popcount(mask);
    }

public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans = 1;
        For(mask, 0, 1 << n) {
            if (__builtin_popcount(mask) <= 1) {
                ++ans;
                continue;
            }
            ans += solve(mask, n, maxDistance, roads);
        }
        return ans;
    }
};