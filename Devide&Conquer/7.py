class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        def mergesort(l, r) -> int:
            if l == r:
                return 0
            mid = (l + r) // 2
            res = mergesort(l, mid) + mergesort(mid + 1, r)
            i, j = l, mid + 1
            while i <= mid:
                while j <= r and nums[i] > 2 * nums[j]:
                    j += 1
                res += j - mid - 1
                i += 1 
            nums[l:r + 1] = sorted(nums[l:r + 1])
            return res
        
        return mergesort(0, len(nums) - 1)