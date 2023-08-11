class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return findKthLargest(nums, 0, nums.size() - 1, k);
    }

private:
    int findKthLargest(vector<int> &nums, int left, int right, int k)
    {
        if (left == right)
            return nums[left];
        int pivot = partition(nums, left, right);
        if (pivot == k - 1)
            return nums[pivot];
        else if (pivot < k - 1)
            return findKthLargest(nums, pivot + 1, right, k);
        else
            return findKthLargest(nums, left, pivot - 1, k);
    }

    int partition(vector<int> &nums, int left, int right)
    {
        int random = rand() % (right - left + 1) + left;
        swap(nums[random], nums[right]);
        int pivot = nums[right];
        int i = left - 1;
        for (int j = left; j < right; j++)
        {
            if (nums[j] > pivot)
                swap(nums[++i], nums[j]);
        }
        swap(nums[++i], nums[right]);
        return i;
    }
};