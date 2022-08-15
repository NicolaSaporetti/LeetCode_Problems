#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> results;
    string temp;
    int sz;
    
    void computeLetterCasePerm(string& s, int pos)
    {
        bool exit = false;
        for(int i=pos;i<sz && !exit;i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                computeLetterCasePerm(s,i+1);
                temp[i]-=32;
                computeLetterCasePerm(s,i+1);
                temp[i]+=32;
                exit = true;
            }
            else if(s[i]>='A' && s[i]<='Z')
            {
                computeLetterCasePerm(s,i+1);
                temp[i]+=32;
                computeLetterCasePerm(s,i+1);
                temp[i]-=32;
                exit = true;
            }
        }
        if(!exit) results.push_back(temp);
    }
    
public:
    vector<string> letterCasePermutation(string s) {
        temp = s;
        sz = s.size();
        computeLetterCasePerm(s,0);
        return results;
    }
};