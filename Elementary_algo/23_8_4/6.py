class Solution:
    def romanToInt(self, s: str) -> int:
        hashtable = dict()
        hashtable['I'] =1
        hashtable['V'] = 5
        hashtable['X'] = 10
        hashtable['L'] = 50
        hashtable['C'] = 100
        hashtable['D'] = 500
        hashtable['M'] = 1000
        num = hashtable[s[0]]
        n = len(s)
        for i in range(1,n):
            if hashtable[s[i-1]] < hashtable[s[i]]:
                num += hashtable[s[i]]-2*hashtable[s[i-1]]
            else:
                num += hashtable[s[i]]

        return num