#include <string>
using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int count[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            count[s[i] - 'a']++;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (count[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};

#include <set>
#include <string>
using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        set<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.find(s[i]) != st.end())
                continue;
            bool flag = true;
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    flag = false;
                    st.insert(s[i]);
                    break;
                }
            }
            if (flag)
                return i;
        }
        return -1;
    }
};