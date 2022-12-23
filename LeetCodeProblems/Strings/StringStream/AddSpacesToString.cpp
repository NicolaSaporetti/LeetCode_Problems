#include <vector>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int sz = s.size();
        int maxIsz = spaces.size();
        int index=0;
        for(int i=0;i<sz;i++)
        {
            if(index>=maxIsz || i!=spaces[index]) res.push_back(s[i]);
            else
            {
                res.push_back(' ');
                res.push_back(s[i]);
                index++;
            }
        }
        return res;
    }
};