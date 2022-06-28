#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> letters(26,0);
        int result =0;
        int sz = s.size();
        for(int i=0;i<sz;i++)
        {
            letters[s[i]-'a']++;
        }
        sort(letters.begin(),letters.end(),greater<int>());
        for(int i=1;i<26;i++)
        {
            if(letters[i]>=letters[i-1] && letters[i]!=0)
            {
                if(letters[i-1]!=0)
                {
                    result += (letters[i]-letters[i-1]+1);
                    letters[i] = letters[i-1]-1;
                }
                else
                {
                    result += (letters[i]-letters[i-1]);
                    letters[i] = letters[i-1];
                }
            }
        }
        return result;
    }
};