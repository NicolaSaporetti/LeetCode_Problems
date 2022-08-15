#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i+needle.size()<=haystack.size();i++)
        {
            bool result = checkNeedleFound(haystack, needle, i);
            if(result) return i;
        }
        return -1;
    }
private:
    bool checkNeedleFound(string& haystack, string& needle, int pos) {
        for(int i=0;i<needle.size();i++)
            if(haystack[pos+i]!=needle[i]) return false;
        return true;
    }
};