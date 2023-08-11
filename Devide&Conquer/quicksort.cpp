#include <vector>
#include <iostream>
#include <random>
using namespace std;

class myQuickSort
{
public:
    void quickSort(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
    }

private:
    void quickSort(vector<int> &nums, int left, int right)
    {
        if (left < right)
        {
            int pivot = partition(nums, left, right);
            quickSort(nums, left, pivot - 1);
            quickSort(nums, pivot + 1, right);
        }
    }

    int partition(vector<int> &nums, int left, int right)
    {
        int random = rand() % (right - left + 1) + left;
        swap(nums[random], nums[right]);
        int pivot = nums[right];
        int i = left - 1;
        for (int j = left; j < right;j++)
        {
            if (nums[j] < pivot)
                swap(nums[++i], nums[j]);
        }
        swap(nums[++i], nums[right]);
        return i;
    }
};

int main()
{
    vector<int> nums = {1, 3, 2, 5, -4, 1, -6, 6, 3, 3, 21, 5, 7, 9, -4, 0};
    myQuickSort().quickSort(nums);
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
    return 0;
}