#include <iostream>
using namespace std;

class Solution {
private:
    int sz_t;
    int sz_s;
public:
    bool isSubsequence(string s, string t) {
        int sz_t = t.size();
        int sz_s = s.size();
        int j=0;
        for(int i=0;i<sz_t && j<sz_s;i++)
        {
            if(t[i]==s[j]) j++;
        }
        if(j==sz_s) return true;
        else return false;
    }
};