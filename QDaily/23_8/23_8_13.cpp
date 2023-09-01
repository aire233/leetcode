class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m--, n--;
        int p = m + n + 1;
        while(n >= 0)
        {
            while(m >= 0 && nums1[m] >= nums2[n])
                nums1[p--] = nums1[m--];
            nums1[p--] = nums2[n--];
        }
    }
};