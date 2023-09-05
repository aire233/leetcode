#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumOperations(string num)
    {
        int n = num.size(), ans;
        for (int i = n - 1; i > 0; i--)
        {
            if (num[i] != '0' && num[i] != '5')
                continue;
            int tag = num[i] == '0' ? 0 : 1;
            ans = n - i - 1;
            printf("%d\n", ans);
            int j = i - 1;
            if (tag)
            {
                for (; j >= 0; j--)
                    if (num[j] == '2' || num[j] == '7')
                    {
                        ans += i - j - 1;
                        return ans;
                    }
            }
            else
            {
                for (; j >= 0; j--)
                    if (num[j] == '0' || num[j] == '5')
                    {
                        ans += i - j - 1;
                        return ans;
                    }
            }
            if (j <= 0)
                return n;
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    cout << sol.minimumOperations("258") << endl;
}