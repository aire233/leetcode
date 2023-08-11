#include<vector>
#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> index(n);
        for(int i = 0; i < n; i++)
            index[i] = i;
        vector<int> res(n, 0);
        mergesort(nums, index, 0, n - 1, res);
        return res;
    }
private:
    void mergesort(vector<int>& nums, vector<int>& index, int l, int r, vector<int>& res)
    {
        if(l >= r)
            return;
        int m = (l + r) / 2;
        mergesort(nums, index, l, m, res);
        mergesort(nums, index, m + 1, r, res);
        merge(nums, index, l , m, r, res);
    }

    void merge(vector<int>& nums, vector<int>& index, int l, int m, int r, vector<int>& res)
    {
        vector<int> temp(r - l + 1);
        int i = l, j = m + 1, k = 0;
        for(; i <= m && j <= r;)
        {
            if(nums[index[i]] <= nums[index[j]])
            {
                res[index[i]] += j - m - 1;
                temp[k++] = index[i++];
            }
            else
            {
                temp[k++] = index[j++];
            }
        }
        while(i <= m)
        {
            res[index[i]] += j - m - 1;
            temp[k++] = index[i++];
        }
        while(j <= r)
        {
            temp[k++] = index[j++];
        }
        for(i = l; i <= r; i++)
        {
            index[i] = temp[i - l];
        }
    }
};