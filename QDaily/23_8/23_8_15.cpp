class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.length();
        vector<pair<string, int>> replace(n, {"", 1});
        for(int i = 0; i < indices.size(); i++)
            if(s.compare(indices[i], sources[i].length(), sources[i]) == 0)
                replace[indices[i]] = {targets[i], sources[i].length()};

        string ans;
        for(int i = 0; i < n; i += replace[i].second)
            if(replace[i].first.empty())
                ans += s[i];
            else
                ans += replace[i].first;
        return ans;
    }
};