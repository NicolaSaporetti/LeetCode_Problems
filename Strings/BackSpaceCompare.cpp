#include <iostream>
using namespace std;

class Solution {
private:
    void simplifyString(string& s)
    {
        int pos =0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#')
            {
                if(pos>0) pos--;
            }
            else
            {
                s[pos++]=s[i];
            }
        }
        s.resize(pos);
    }
public:
    bool backspaceCompare(string s, string t) {
        simplifyString(s);
        simplifyString(t);
        if(s.compare(t)==0) return true;
        else return false;
    }
};

int main()
{
    Solution solution;
    return 0;
}