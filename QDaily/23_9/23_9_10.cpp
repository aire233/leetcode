class Solution { // topological sort
public:
    vector<int> findOrder(int n, vector<vector<int>>& prr)
    {
        vector<int> ans, degs(n);
        vector<vector<int>> edges(n);
        for(auto& p: prr)
        {
            edges[p.back()].emplace_back(p.front());
            degs[p.front()]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) if(!degs[i]) q.push(i);
        while(!q.empty())
        {
            ans.emplace_back(q.front());
            for(auto& a: edges[q.front()])
                if(!--degs[a])q.push(a);
            q.pop();
        }
        return ans.size() == n ? ans : vector<int>{};
    }
};