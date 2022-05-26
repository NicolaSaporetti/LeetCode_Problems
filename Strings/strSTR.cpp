#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
public:
    int strStr(string haystack, string needle) {
        bool matchFound = false;
        int result =0;
        if(needle.size()==0) return 0;
        for(int i=0;i<haystack.size() && matchFound==false;i++)
        {
            bool patternMatch = true;
            if(i+needle.size()<=haystack.size())
            {
                for(int j=0;j<needle.size() && patternMatch==true;j++)
                {
                    if(needle[j]!=haystack[j+i]) patternMatch=false;
                }
                if(patternMatch==true)
                {
                    matchFound = true;
                    result = i;
                }
            }
        }
        if (matchFound == true) return result;
        else return -1;
    }
};

int main()
{
    Solution solution;
    bool testResult = true;
    string s ="a";
    string p ="a";
    cout<<solution.strStr(s,p)<<endl;
    return 0;
}