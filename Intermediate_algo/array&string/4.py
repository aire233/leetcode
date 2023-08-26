class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s: return 0
        l = 0
        ans = 0
        occ = set()
        n = len(s)
        for i in range(n):
            while s[i] in occ:
                occ.remove(s[l])
                l += 1
            ans = max(ans, i - l + 1)
            occ.add(s[i])
        return ans