#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, int parent, const vector<vector<int>>& graph, const vector<int>& nums, int k, vector<vector<long long>>& dp) {
        // dp[node][0] 表示不使用 XOR 操作的最大值
        // dp[node][1] 表示使用 XOR 操作的最大值
        dp[node][0] += nums[node];
        dp[node][1] += nums[node] ^ k;

        for (int child : graph[node]) {
            if (child == parent) continue;
            dfs(child, node, graph, nums, k, dp);

            int x = max(dp[node][0] + dp[child][0], dp[node][1] + dp[child][1]);
            int y = max(dp[node][1] + dp[child][0], dp[node][0] + dp[child][1]);
            dp[node][0] = x;
            dp[node][1] = y;
        }
    }

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> a;
        long long ans = 0;
        for (int i = 0; i < n; ++i)
            a.push_back((nums[i] ^ k) - nums[i]), ans += nums[i];
        sort(a.begin(), a.end(), greater<int>());
        for (int i = 0; i < n; i += 2)
            if (a[i] + a[i + 1] > 0)
                ans += a[i] + a[i + 1];
        return ans;
    }
};
