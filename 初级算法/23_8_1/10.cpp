class Solution { // KMP
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if (n == 0) return 0;
        vector<int> next = getNext(needle);
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        if (j == n) return i - j;
        return -1;
    }

    vector<int> getNext(string needle) {
        int n = needle.length();
        vector<int> next(n, 0);
        int i = 0, j = -1;
        next[0] = -1;
        while (i < n - 1) {
            if (j == -1 || needle[i] == needle[j]) {
                i++;
                j++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
        return next;
    }
};