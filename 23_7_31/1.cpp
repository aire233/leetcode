// https://leetcode.cn/leetbook/read/top-interview-questions-easy/x2f9gg/
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        int p1 = 0, p2 = 1;
        for (; p2 < nums.size();p2++)
        {
            if (nums[p1] != nums[p2])
                nums[++p1] = nums[p2];
        }
        return ++p1;
    }
};