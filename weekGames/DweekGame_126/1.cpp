#include "bits/stdc++.h"
#define For(i, a, b) for (auto i = a; i < (b); ++i)
#define Rof(i, a, b) for (auto i = a; i > (b); --i)
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
#define LL long long
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

class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        LL ans = 0LL;
        for (auto x : nums) {
            int res = 0, n = 0;
            while (x) {
                chmax(res, x % 10);
                x /= 10;
                n++;
            }
            int tmp = 0;
            while (n--) {
                tmp = tmp * 10 + res;
            }
            ans += tmp;
        }
        return ans;
    }
};