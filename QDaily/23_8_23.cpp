#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) 
    {
        int deg[n + 1];
        memset(deg, 0, sizeof(deg));
        unordered_map<int, int> mp;
        for (auto& e : edges)
        {
            int x = e[0], y = e[1];
            if (x > y) swap(x, y);
            deg[x]++, deg[y]++;
            mp[x << 16 | y]++;
        }

        int sorted_deg[n + 1];
        memcpy(sorted_deg, deg, sizeof(deg));
        sort(sorted_deg + 1, sorted_deg + n + 1);
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++)
        {
            int l = 1, r = n;
            while (l < r)
            {
                if (sorted_deg[l] + sorted_deg[r] > queries[i]) ans[i] += r - l, r--;
                else l++;
            }
            for (auto& [k, v]: mp)
            {
                int s = deg[k >> 16] + deg[k & 0xffff];
                if (s > queries[i] && s - v <= queries[i]) 
                {
                    ans[i]--;
                    // printf("%d %d %d %d\n", k >> 16, k & 0xffff, s, v);
                }
            }
        }
        return ans;
    }
};

int main()
{
    int n = 4;
    vector<vector<int>> edges = {{1,2},{2,4},{1,3},{2,3},{2,1}};
    vector<int> queries = {2,3};
    Solution sol;
    auto ans = sol.countPairs(n, edges, queries);
    for (auto& x : ans) printf("%d ", x);
    return 0;
}