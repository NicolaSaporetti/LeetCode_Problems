#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        computeIP(s,0, 3);
        return result;
    }
private:
    void computeIP(string& s, int pos, int left)
    {
        if(left<0 || pos>=s.size())
        {
            if(pos>=s.size() && left<0) result.push_back(temp.substr(0,temp.size()-1));
        }
        else
        {
            if(s[pos]=='0')
            {
                temp+=s[pos];
                temp+='.';
                computeIP(s,pos+1,left-1);
                temp.pop_back();
                temp.pop_back();
            }
            else
            {
                for(int i=0;i<3 && pos+i<s.size()-left;i++)
                {
                    temp+=s.substr(pos,i+1);
                    temp+='.';
                    if(stoi(s.substr(pos,i+1))<256) computeIP(s,pos+i+1,left-1);
                    for(int j=0;j<=i+1;j++) temp.pop_back();
                }
            }
        }
    }

    vector<string> result;
    string temp;
};