#include <vector>
#include <iostream>
using namespace std;

class myMergeSort
{
public:
    void mergeSort(vector<int> &nums)
    {
        vector<int> tmp(nums.size(), 0);
        mergeSort(nums, 0, nums.size() - 1, tmp);
    }

private:
    void mergeSort(vector<int> &nums, int left, int right, vector<int> &tmp)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid, tmp);
            mergeSort(nums, mid + 1, right, tmp);
            merge(nums, left, mid, right, tmp);
        }
    }

    void merge(vector<int> &nums, int left, int mid, int right, vector<int> &tmp)
    {
        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
                tmp[k++] = nums[i++];
            else
                tmp[k++] = nums[j++];
        }
        while (i <= mid)
            tmp[k++] = nums[i++];
        while (j <= right)
            tmp[k++] = nums[j++];
        for (int i = left; i <= right; i++)
            nums[i] = tmp[i];
    }
};

int main()
{
    vector<int> nums = {1, 3, 2, 5, -4, 1, -6, 6, 3, 3, 21, 5, 7, 9, -4, 0};
    myMergeSort().mergeSort(nums);
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
    return 0;
}