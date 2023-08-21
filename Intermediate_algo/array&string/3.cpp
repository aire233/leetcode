class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> u_mapRes;
        for (auto& str : strs) {
            string count(26, '0');

            for (auto& c : str) {
                count[c - 'a'] += 1;
            }
            u_mapRes[count].push_back(str);
        }
        for (auto& pair : u_mapRes) {
            res.push_back(pair.second);
        }
        return res;
    }
};