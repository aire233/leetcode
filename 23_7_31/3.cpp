class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size(), i = 0, tmp;
        k %= n;
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }

    void reverse(vector<int> &nums, int start, int end)
    {
        int tmp;
        while (start < end)
        {
            tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;end--;
        }
    }
};