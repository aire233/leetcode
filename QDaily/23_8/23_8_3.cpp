class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool in_block = false;
        vector<string> res;
        string newLine = "";
        for(auto line : source)
        {
            for(int i = 0; i < line.size(); i++)
            {
                if(in_block)
                {
                    if(i + 1 < line.size() && line[i] == '*' && line[i + 1] == '/')
                    {
                        in_block = false;
                        i++;
                    }
                }
                else
                {
                    if(i + 1 < line.size() && line[i] == '/' && line[i + 1] == '/')
                        break;
                    else if(i + 1 < line.size() && line[i] == '/' && line[i + 1] == '*')
                    {
                        in_block = true;
                        i++;
                    }
                    else
                        newLine += line[i];
                }    
            }
            if(!in_block && newLine.size() != 0)
            {
                res.push_back(newLine);
                newLine = "";
            }      
        }
        return res;
    }
};