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
                                                            ,iLG8CCCCGti,                                                       
                                                   iCCCC88L1;,..........,1LCCCCC8L,                                             
                                            .fCC8f:.,,....       ..,...,.     ....:fCC8L..,,;:i:;:,.                            
                          1CCCCGGGCCCG8LGCCGi.....,.,,....       ..,....,     ...,......tCGCt  .    .:ifLCCC81                  
                     ,CG8i           LGC ..,,,   .,,....,         ...,..       ,,..,..     .iCGC .          CGCG                
                   :LC            CGC.  .,.,,,    .......          ..,..       ......  .ift,  ..GG8:        CL,C,               
                  :GGC        .CGL      ....,      .....                             ..G   i8C:   .fGC,     Gi,Cf               
                  CCiC.     CGL   ..tCLCCGGC                                                 .  .   .,8Lf  ;C,,CG               
                 tGC,C.  1CG        .                                                                  .LCLfC.,GG               
                 CG;,G,fGL .                                                                             .LGC,:GC               
                .GC,.8CL                                                                                   .CCfGC               
                fGiGGC.                                                                                      .8C8               
                CGCC.                                                                                          1Gt              
                CGG                                                                                             ,CC             
               iC1                                                                                                88            
              ,C1...                                                                    .,,.                    .  LC           
              C1                      .                                            iGCGGGCCGGCCG;                  .LG          
             CC                  :fLGCCLGGGGCL;                                 ,GGCGGCC    tGGGGGG,                 GC.        
            LC              . .tGGG:    8GGGGGGGG,                            .LGGGGGGGG    GGGGGGGCt                .CC        
            Gi               iCGGGC8   1CGGCGGGGGCL                           LCGGGGCGGGGGCGGGGGGGGGGf                ,G;       
           C8               1CGGGGGGGGGGGGGGGGGGGCGL                         ;GCGGGGGGGGGGGGGGGGGGGGGG:                88       
           Ct              ,GGGGGGGGGGGGGGGGGGGGGGGGi                        1CGGGGGGGGGGGGGGGGGGGGGGCi                1C       
          i8               ;CCGGGGGGGGGGGGGGGGGGGGGGt .            .         iGCGGGGGGGGGGGGGGGGGGGGGG:                .G:      
          GC               :CGGGGGGGGGGGGGGGGGGGGGGG1       .  ,,             LGGGGGGGGGGGGGGGGGGGGGGf                  C1      
          8L,..,.          .tCCGGGGGGGGGGGGGGGGGCGGG     .    ,GGC            .LGGGGGGGGGGGGGGGGGCGCf.             ,....Ct      
          C1.....,,,,,,,..   fCGGGGGGGGGGGGGGGGGCGG,    .1L . tCfLG;  tt  .   . ;GGGGGGGGGGGGGGGCGG:   .,,,,,,,:,,,,,,,.C1      
         .Ci .,,,,:,..:,:,,,  :GGGGGGGGGGGGGCGCGC1         Ct11;::;;iL            .1CGGGGGCGGGGGi.    ,,,:Ci:.C,,.Gt;;..C,.     
    .,;1fCCGCGC.C..,8:,;C,,,,   .tGCGGGGGGGGGCL:           Gi::::::::1                 .,,:,          ,,,C;.,8,,,C.,,:;fG1LGC8CG
.C11,     CC,..i::,t,,,t,,,,         ,;ii;:.               Gi::::::::;                                 .,:,,,,,,::,,...0G       
          tG..,;i,,,,,,...                                 Gi:::::::::                                           .tGCGCLf:      
     .:LCGGGGL1  ..                                        L;:::::::::,.                                       ti     CL .tCGC  
 :CCL;     iG. .;8 .                                       G;:::::::::                                          ,CCL;CG         
            GCG8.                                          G;::::::::t                                         ...,.CCGG:       
       .fGCG GC ,.,.                                       .1:::::::,1                                           .:CG   :8G8    
    GGCL      1C1                                           1i:;,:;,t  .                                    .    CG,            
                8C,.                                        . iLGLi.                                           GCt              
                  GCL                                                                                       .88i                
                    ,8CL                                                                                 :CCC                   
                       .GCCCt.                                                                    . ,LCC8;                      
                             ,fGCCCCCCC8CLt;:.                                          .  ,:LCC8CCL.                           
                                            .:itCGGGGGGGGGGGCCGGCCCGCCCCCCCCCCCCCGGCGCCG8Gi,*/


class Solution {
public:
    using map = unordered_map<int, int>;
    int sumOfPowers(vector<int>& nums, int k) {
        int n = sz(nums), res = _;
        sort(all(nums));
        vector<vector<map>> dp(n, vector<map>(k + 1));
        For(i, 0, n) {
            dp[i][1][inf] = 1;
            For(j, 0, i) {
                int diff = abs(nums[i] - nums[j]);
                For(p, 2, k + 1) {
                    for (auto &[v, cnt] : dp[j][p - 1]) {
                        dp[i][p][min(v, diff)] = (dp[i][p][min(v, diff)] + cnt) % mod;
                    }
                }
            }

            for(auto &[v, cnt] : dp[i][k]) {
                res = (res + 1ll * v * cnt) % mod;
            }
        }

        return res;
    }
};