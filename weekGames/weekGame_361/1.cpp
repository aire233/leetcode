class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {
        int ans = 0;
        for (int i = low; i <= high; i++)
        {
            int n = log10(i) + 1;
            if (n % 2)
                continue;
            int t = i, l = 0, h = 0;
            for (int j = 0; j < n / 2; j++)
            {
                l += t % 10;
                t /= 10;
            };
            for (int j = 0; j < n / 2; j++)
            {
                h += t % 10;
                t /= 10;
            };
            if (l == h)
                ans++;
        }
        return ans;
    }
};