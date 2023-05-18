#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        computePartition(s,0);
        return result;
    }
private:
    void computePartition(string& s, int pos)
    {
        if(pos>=s.size()) result.push_back(temp);
        else
        {
            for(int i=pos;i<s.size();i++)
            {
                if(isPalindrome(s, pos, i))
                {
                    temp.push_back(s.substr(pos,i-pos+1));
                    computePartition(s, i+1);
                    temp.pop_back();
                }
            }
        }
    }

    bool isPalindrome(string& s, int start, int e)
    {
        int sz = e-start+1;
        for(int i=0;i<sz/2;i++) if(s[start+i]!=s[e-i]) return false;
        return true;
    }

    vector<vector<string>> result;
    vector<string> temp;
};