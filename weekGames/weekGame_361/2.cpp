class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size(), i = n - 1, ans = -1;
        int f[2] = {0, 0}; // 0 or 5
        while(i >= 0)
        {
            if(num[i] == '0')
            {
                if(f[0]) return ans;
                f[0] = 1;
            }
            else if(num[i] == '5')
            {
                if(f[0]) return ans;
                f[1] = 1;
            }
            else if(f[1] && (num[i] == '2' || num[i] == '7'))
            {
                return ans;
            }
            ans++, i--;
        }
        return n - f[0];
    }
};