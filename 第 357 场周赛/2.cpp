#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int _m;
    bool canSplitArray(vector<int> &nums, int m)
    {
        int n = nums.size();
        if (n == 1)
            return true;
        _m = m;

        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                for (int _= 0; _ < n; _++)
                {
                    int j = i + len - 1;
                    if(!dp[i][j])
                        dp[i][j] = (j > 0 && dp[i][j - 1] && canSplit(nums, i, j)) ||
                            (i > 0 && dp[i - 1][j] && canSplit(nums, i, j));
                }
            }
        }
        cout << "dp:" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        return dp[0][n - 1];
    }

    bool canSplit(vector<int> &nums, int begin, int end)
    {
        if(begin == end)
            return true;
        int sum = 0;
        for (int i = begin; i <= end; i++)
            sum += nums[i];
        if (sum >= _m)
            return true;
        return false;
    }
};

int main()
{
    vector<int> nums = {2, 3, 3, 2, 3};
    int m = 6;
    Solution s;
    cout << s.canSplitArray(nums, m) << endl;
    return 0;
}