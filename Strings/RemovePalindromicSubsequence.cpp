#include <iostream>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        int sz = s.size()-1;
        int j=0;
        for(;j<sz/2;j++)
        {
            if(s[j]!=s[sz-j]) break;
        }
        if(j>=sz/2) return 1;
        else return 2;
    }
};