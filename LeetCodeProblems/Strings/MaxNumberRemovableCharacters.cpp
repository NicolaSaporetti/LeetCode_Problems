#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:    
    bool checkIfStringIsSubset(string& s, string& p)
    {
        int szS = s.size();
        int szP = p.size();
        int posP = 0;
        for(int i=0;i<szS && posP<szP;i++)
        {
            if(p[posP]==s[i]) posP++;   
        }
        return (posP>=szP)? true : false;
    }
    
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int minRemoval = 0;
        int maxRemoval = removable.size();
        int sz = s.size();
        while(minRemoval<maxRemoval)
        {
            int value = (minRemoval+maxRemoval+1)/2;
            string newS = s;
            if(value!=0)
            {
                for(int i=0;i<value;i++) newS[removable[i]]='0';
                int pos = 0;
                for(int i=0;i<sz;i++)
                {
                    if(newS[i]!='0')
                    {
                        newS[pos++]=newS[i];
                    }
                }
                newS.resize(pos);
            }
            bool isStringSubset = checkIfStringIsSubset(newS, p);
            if(isStringSubset)
            {
                minRemoval = value;
            }
            else
            {
                maxRemoval= value-1;
            }
        }
        return minRemoval;
    }
};