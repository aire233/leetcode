class Solution {
public:
    string finalString(string s) {
        string res == "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'i'){
                reverse(res.begin(), res.end());
                i++;
            }
            else
                res.push_back(s[i]);
        }
        return res;
    }
};