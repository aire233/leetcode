class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        while (i < n && s[i] == ' ') i++;
        if (i == n) return 0;
        int sign = 1;
        if (s[i] == '+') i++;
        else if (s[i] == '-') {
            sign = -1;
            i++;
        }
        long long res = 0;
        while (i < n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');
            if( res > INT_MAX && sign == 1) return INT_MAX;
            if( res > INT_MAX && sign == -1) return INT_MIN;
            i++;
        }
        return res * sign;
    }
};