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
        mergeSort(nums, index, 0, n - 1, res);
        return res;
    }

    void mergeSort(vector<int>& nums, vector<int>& index, int l, int r, vector<int>& res)
    {
        if(l >= r)
            return;
        int mid = (r + l) / 2;
        mergeSort(nums, index, l, mid, res);
        mergeSort(nums, index, mid + 1, r, res);
        merge(nums, index, l, mid, r, res);
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
        for(int i = l; i <= r; i++)
        {
            index[i] = temp[i - l];
        }
    }
};