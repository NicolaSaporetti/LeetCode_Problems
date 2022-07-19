#include <iostream>
#include <vecotr>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char result;
        vector<int> letters(26,0);
        for(int i=0;i<s.size();i++)
        {
            letters[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++)
        {
            letters[t[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(letters[i]<0)
            {
                result = i+'a';
                break;
            }
        }
        return result;
    }
};