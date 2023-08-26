class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        for(int i = 0; i < columnTitle.size(); i++)
            sum = (columnTitle[i] - 'A' + 1) + sum * 26;
        return sum;
    }
};