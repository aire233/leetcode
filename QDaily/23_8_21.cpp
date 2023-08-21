class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0, n = start.size();
        while(i < n && j < n)
        {
            while(i < n && start[i] == '_') i++;
            while(j < n && target[j] == '_') j++;
            if(i < n && j < n)
            {
                if(start[i] != target[j]) return false;
                if(start[i] == 'R' && i > j) return false;
                if(start[i] == 'L' && i < j) return false;
                i++, j++;
            }
        }
        for(;i < n; i++)
            if(start[i] != '_') return false;
        for(;j < n; j++)
            if(target[j] != '_') return false;
        return true;
    }
};