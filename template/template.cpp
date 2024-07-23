#include "bits/stdc++.h"
#define For(i, a, b) for (auto i = a; i < (b); ++i)
#define Rof(i, a, b) for (auto i = a; i > (b); --i)
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
#define LL long long
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;

template <class A, class B> string to_string(const pair<A, B> &p);
template <class A, class B, class C> string to_string(const tuple<A, B, C> &p);
template <class A, class B, class C, class D>
string to_string(const tuple<A, B, C, D> &p);
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
template <class A, class B, class C, class D>
string to_string(const tuple<A, B, C, D> &p) {
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