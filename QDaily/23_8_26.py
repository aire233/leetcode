class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        n = len(nums)
        i = 0
        rec = []
        while i ^ n:
            low = i
            while i ^ (n - 1) and nums[i] == nums[i+1] - 1:
                i += 1
            s = str(nums[low])
            if low ^ i:
                s += "->" + str(nums[i])
            rec.append(s)
            i += 1
        return rec