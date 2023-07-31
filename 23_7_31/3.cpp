class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size(), i = 0, tmp;
        int vis[n];
        memset(vis, 0, sizeof(vis));
        k = k % n;
        while (1)
        {
            if (vis[i] == 1)
                break;
            tmp = nums[i + k], nums[i + k] = nums[i], vis[i] = 1;
            i = (i + k) % n;
        }
    }
};