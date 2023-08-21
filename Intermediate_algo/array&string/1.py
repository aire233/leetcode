class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        n = len(nums)
        for i in range(n - 2):
            x = nums[i]
            if i > 0 and x == nums[i - 1]:
                continue
            j = i + 1
            k = n - 1
            while j < k:
                s = nums[j] + x + nums[k]
                if s > 0:
                    k -= 1
                elif s < 0:
                    j += 1
                else:
                    ans.append([nums[j], x, nums[k]])
                    j += 1
                    while nums[j] == nums[j - 1] and j < k:
                        j += 1
                    k -= 1
                    while nums[k] == nums[k + 1] and j < k:
                        k -= 1
        return ans