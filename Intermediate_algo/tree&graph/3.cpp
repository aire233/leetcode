class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n < 2) return s;
        int dp[n][n], max_len = 1, left = 0;
        memset(dp, 0, sizeof(dp));
        for(int j = 1; j < n; j++)
            for(int i = 0; i < j; i++)     
            {
                if(s[i] != s[j])continue;
                if(j - i <= 2)dp[i][j] = 1;
                else dp[i][j] = dp[i+1][j-1];
                if(dp[i][j] && j - i + 1 > max_len)
                {
                    left = i;
                    max_len = j - i + 1;
                }
            }
        return s.substr(left, left + max_len);
    }
};