#include <iostream>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int number =0;
        bool odd = false;
        vector<int> letters(52,0);
        for(auto x : s)
        {
            if(x-'a'>=0 && x-'a'<26)
                letters[x-'a']++;
            else
                letters[26+x-'A']++;
        }
        for(auto x: letters)
        {
            number+=(x-x%2);
            if(!odd) odd = (x%2)? true : false;
        }
        if(odd) number++;
        return number;
    }
};