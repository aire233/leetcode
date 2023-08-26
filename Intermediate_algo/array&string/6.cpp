class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int a = INT_MAX, b = INT_MAX;
        for(auto &x: nums)
        {
            if(x > b) return 1;
            else if (x > a) b = x;
            else a = x;
        }
        return false;
    }
};