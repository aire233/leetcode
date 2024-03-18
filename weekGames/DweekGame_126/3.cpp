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

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> freq(26, 0);  // 记录每个字母出现的频率
        for (char& c : s) {
            if (c != '?') {
                // 更新非问号字符的频率
                freq[c - 'a']++;
            }
            else {
                // 对于问号，找到替换后分数增加最小的字符
                for (int i = 0; i < 26; ++i) {
                    if (freq[i] == 0) {
                        // 如果当前字符i未出现过，替换它，并停止循环
                        c = 'a' + i;
                        freq[i]++;
                        break;
                    }
                }
            }
        }
        return s;
    }
};
// "abcdefghijklmnopqrstuvwxy??"
