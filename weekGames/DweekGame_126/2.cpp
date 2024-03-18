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
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> marked(n, false);  // 初始化标记数组
        vector<long long> answer;       // 存储每次操作后未标记元素的总和
        long long unmarkedSum = 0;      // 未标记元素的总和

        // 创建一个元素值和索引的对的数组，并按元素值排序
        vector<pair<int, int>> elements;
        for (int i = 0; i < n; ++i) {
            elements.emplace_back(nums[i], i);
            unmarkedSum += nums[i];
        }
        sort(elements.begin(), elements.end());

        // 处理每个查询
        for (const auto& q : queries) {
            int index = q[0], k = q[1];

            // 标记 indexi 对应的元素
            if (!marked[index]) {
                marked[index] = true;
                unmarkedSum -= nums[index];
            }

            // 标记 k 个未标记的最小元素
            if (k) {
                int i = 0;
                while (i < n) if (marked[i]) i++;
                for (int j = 0; j < k; ++j) {
                    if (i == n) break;
                    if (!marked[i]) {
                        marked[i] = true;
                        unmarkedSum -= nums[i];
                    }
                    do i++; while (i < n && marked[i]);
                }
            }

            // 将当前未标记元素的总和加入答案数组
            answer.push_back(unmarkedSum);
        }

        return answer;
    }
};