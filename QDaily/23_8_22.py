class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        res, l  = 0, 0
        n = len(seats)
        while l < n and not seats[l]:
            l += 1
        res = max(res, l)
        while l < n:
            r = l + 1
            while r < n and not seats[r]:
                r += 1
            if r == n:
                res = max(res, r - l - 1)
            else:
                res = max(res, (r - l) // 2)
            l = r
        return res