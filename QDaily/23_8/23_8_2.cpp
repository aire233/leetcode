class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        set<int> same;
        int n = fronts.size(), i, ans = 2001;
        for(i = 0; i < n; i++)
        {
            if(fronts[i]==backs[i]) same.insert(fronts[i]);
        }
        for(i = 0; i < n; i++)
        {
            int lower = fronts[i] < backs[i] ? fronts[i] : backs[i];
            if(same.find(lower) != same.end())
            {
                lower = fronts[i] > backs[i] ? fronts[i] : backs[i];
                if(same.find(lower) != same.end())
                    continue;
            }
            if(lower < ans) ans = lower;
        }
        if(ans == 2001) return 0;
        return ans;
    }
};