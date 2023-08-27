#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        // if(n == 1) return target;
        long long sum = 0;
        int rec[200000] = {0};
        for(int l = 0, j = 1; l < n; j++)
        {
            if(rec[j] == 0)
            {
                if(target - j > 0) rec[target - j] = 1;
                sum += j;
                l++;
            }
        }
        return sum;
    }
};

/*
class Solution:
    def minimumSum(self, n: int, k: int) -> int:
        if n <= k // 2: return n * (n + 1) // 2
        return (k // 2) * (k // 2 + 1) // 2 + (2 * k + n - k // 2 - 1) * (n - k // 2) // 2
*/

int main()
{
    int n = 1, target = 1;
    Solution sol;
    cout << sol.minimumPossibleSum(n, target) << endl;
}