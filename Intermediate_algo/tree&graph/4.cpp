#define For(i, a, b) for (int i = a; i < b; i++)
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n < 2)
            return s;
        int dp[n][n], max_len = 1, left = 0;
        memset(dp, 0, sizeof(dp));
        For(j, 1, n) For(i, 0, j) 
        // For(i, 0, j) For(j, 1, n) is wrong
        {
            if (s[i] != s[j])continue;
            if (j - i <= 2)dp[i][j] = 1;
            else dp[i][j] = dp[i + 1][j - 1];
            if (dp[i][j] && j - i + 1 > max_len)
            {
                left = i;
                max_len = j - i + 1;
            }
        }
        return s.substr(left, max_len);
    }
};