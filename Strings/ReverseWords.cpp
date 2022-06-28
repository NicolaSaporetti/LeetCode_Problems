#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int sz = s.size();
        for(int i=0;i<sz;)
        {
            int j=i+1;
            while(j<sz && s[j]!=' ')j++;
            reverse(s.begin()+i,s.begin()+j);
            i=j+1;
        }
        return s;
    }
};