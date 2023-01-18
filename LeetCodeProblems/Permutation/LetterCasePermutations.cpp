#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        temp = s;
        sz = s.size();
        computeLetterCasePerm(s,0);
        return results;
    }
private:    
    void computeLetterCasePerm(string& s, int pos)
    {
        while(pos<sz && s[pos]>='0' && s[pos]<='9') pos++;
        if(pos>=sz) results.push_back(temp);
        else
        {
            computeLetterCasePerm(s,pos+1);
            if(s[pos]>='a' && s[pos]<='z')
            {
                temp[pos]-=32;
                computeLetterCasePerm(s,pos+1);
                temp[pos]+=32;
            }
            else
            {
                temp[pos]+=32;
                computeLetterCasePerm(s,pos+1);
                temp[pos]-=32;
            }
        }
    }

    vector<string> results;
    string temp;
    int sz;
};