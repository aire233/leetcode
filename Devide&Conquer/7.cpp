class Solution
{
public:
    int reversePairsRecursive(vector<int> &nums, int left, int right)
    {
        if (left == right)
            return 0;
        int mid = (left + right) / 2, ans;
        ans = reversePairsRecursive(nums, left, mid) + reversePairsRecursive(nums, mid + 1, right);

        int p = left, q = mid + 1;
        while (p <= mid)
        {
            while (q <= right && nums[p] > 2 * nums[q])
                q++;
            ans += q - mid - 1;
            p++;
        }

        int i = left, j = mid + 1, k = 0;
        vector<int> res(right - left + 1);
        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
                res[k++] = nums[i++];
            else
                res[k++] = nums[j++];
        }
        while (i <= mid)
            res[k++] = nums[i++];
        while (j <= right)
            res[k++] = nums[j++];

        // don't forget to copy the sorted array back
        for (int i = 0; i < right - left + 1; i++)
            nums[left + i] = res[i];
            
        return ans;
    }

    int reversePairs(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        return reversePairsRecursive(nums, 0, nums.size() - 1);
    }
};