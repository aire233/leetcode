class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size(), len = 1, tail[n];
        tail[0] = nums[0];
        for (int i = 1; i < n; i++)
            if (nums[i] > tail[len - 1])
                tail[len++] = nums[i];
            else
                tail[lower_bound(tail, tail + len, nums[i]) - tail] = nums[i];
        return len;
    }
};