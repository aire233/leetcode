class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size(), index = 0, i = 0;
        for (; i < n; i++)
            if (nums[i] != 0)
                nums[index++] = nums[i];
        for (; index < n; index++)
            nums[index] = 0;
    }
};

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size(), i = 0, j = 0;
        for (; i < n && j < n; j++)
        {
            if (nums[j] == 0)
                i++;
            else if (i != 0)
                swap(nums[j - i], nums[j]);
        }
    }
};