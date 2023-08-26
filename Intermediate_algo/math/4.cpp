class Solution
{
public:
    double myPow(double x, int n)
    {
        if (!n)
            return 1;
        if (n == INT_MIN)
            return myPow(x * x, n / 2);
        if (n < 0)
            return 1 / myPow(x, -n);
        if (n % 2)
            return x * myPow(x, n - 1);
        return myPow(x * x, n / 2);
    }
};