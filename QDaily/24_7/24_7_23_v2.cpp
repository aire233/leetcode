#include "bits/stdc++.h"
#define For(i, a, b) for (auto i = a; i < (b); ++i)
#define Rof(i, a, b) for (auto i = a; i > (b); --i)
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
#define LL long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define pii pair<int, int>
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;

template <class A, class B> string to_string(const pair<A, B> &p);
template <class A, class B, class C> string to_string(const tuple<A, B, C> &p);
template <class A, class B, class C, class dp>
string to_string(const tuple<A, B, C, dp> &p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; }
template <size_t L> string to_string(const bitset<L> &x) {
  return x.to_string();
}
template <class A, class T = typename A::value_type>
string to_string(const A &v) {
  bool first = 1;
  string res = "{";
  for (const auto &x : v) {
    if (!first)
      res += ", ";
    first = 0;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <class A, class B> string to_string(const pair<A, B> &p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class A, class B, class C> string to_string(const tuple<A, B, C> &p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <class A, class B, class C, class dp>
string to_string(const tuple<A, B, C, dp> &p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
#include <iostream>
void debug_out() { std::cerr << std::endl; }
template <class H, class... T> void debug_out(const H &h, const T &...t) {
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
static auto _ = []() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    return 0;
}();

/*
 /\_/\  
( o.o ) 
 > ^ <
*/

class Solution {
public:
    int sumOfPowers(vi& nums, int k) {
        int n = sz(nums); sort(all(nums)); vi vals;
        For(i, 0, n) For(j, 0, i) {
            vals.push_back(nums[i] - nums[j]);
        }
        vals.push_back(inf); sort(all(vals));
        vals.erase(unique(all(vals)), vals.end());

        vvvi dp(n, vector(k + 1, vector(sz(vals), 0)));
        vvi border(n, vector(k + 1, 0));
        vvi sum(k + 1, vector(sz(vals), 0));
        vvi suf(n, vector(k + 1, 0));

        For(i, 0, n) {
            For(j, 0, i) {
                int pos = lower_bound(all(vals), nums[i] - nums[j]) - vals.begin();
                For(p, 1, k + 1) {
                    while (border[j][p] < pos) {
                        sum[p][border[j][p]] = (sum[p][border[j][p]] - suf[j][p] + mod) % mod;
                        sum[p][border[j][p]] = (sum[p][border[j][p]] + dp[j][p][border[j][p]]) % mod;
                        suf[j][p] = (suf[j][p] - dp[j][p][border[j][p]] + mod) % mod;
                        border[j][p]++;
                        sum[p][border[j][p]] = (sum[p][border[j][p]] + suf[j][p]);
                    }
                }
            }

            dp[i][1][sz(vals) - 1] = 1;
            For(p, 2, k + 1) For(v, 0, sz(vals)) {
                dp[i][p][v] = sum[p - 1][v];
            }
            For(p, 1, k + 1) {
                For(v, 0, sz(vals)) {
                    suf[i][p] = (suf[i][p] + dp[i][p][v]) % mod;
                }
                sum[p][0] = (sum[p][0] + suf[i][p]) % mod;
            }
        }

        int res = 0;
        For(i, 0, n) For(v, 0, sz(vals)) {
            res = (res + 1ll * vals[v] * dp[i][k][v] % mod) % mod;
        }
        return res;
    }
};