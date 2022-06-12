#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> myS;
    int newIndex;
    int skips;
    
    void processFinalPart(string& s, string& result)
    {
        int arrIndex = 0;
        while(newIndex+skips<s.size())
        {
            if(arrIndex<myS.size() && newIndex+skips==myS[arrIndex])
            {
                skips++;
                arrIndex++;
            }
            else
            {
                result[newIndex]=s[newIndex+skips];
                newIndex++;
            }
        }
        result.resize(newIndex);
    }
public:
    string minRemoveToMakeValid(string s) {
        string result(s.size(),'a');
        newIndex = 0;
        skips = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') myS.push_back(i);
            if(s[i] == ')')
            {
                if(!myS.empty())
                {
                    myS.pop_back();
                }
                else
                {
                    for(;newIndex+skips<i;newIndex++)
                    {
                        result[newIndex]=s[newIndex+skips];
                    }
                    skips++;
                }
            }
        }
        processFinalPart(s,result);
        return result;
    }
};