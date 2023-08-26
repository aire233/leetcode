#include <iostream>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        int slow = squareSum(n), fast = squareSum(slow);
        while(slow != fast)
        {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        }
        return slow == 1;
    }

    int squareSum(int n)
    {
        int sum = 0;
        while(n)
        {
            int tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    for(int i = 1; i <= 100; i++)
        if(sol.isHappy(i))
            cout << "s[" << i << "] = " << 1 << ";" << endl;
        
}

class Solution {
public:
    bool isHappy(int n) {
        bool s[101] = {0};
        s[1] = 1;
        s[7] = 1;
        s[10] = 1;
        s[13] = 1;
        s[19] = 1;
        s[23] = 1;
        s[28] = 1;
        s[31] = 1;
        s[32] = 1;
        s[44] = 1;
        s[49] = 1;
        s[68] = 1;
        s[70] = 1;
        s[79] = 1;
        s[82] = 1;
        s[86] = 1;
        s[91] = 1;
        s[94] = 1;
        s[97] = 1;
        s[100] = 1;
        while(n > 100)
            n = squareSum(n);
        return s[n];
    }

    int squareSum(int n)
    {
        int sum = 0;
        while(n)
        {
            int tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }
};