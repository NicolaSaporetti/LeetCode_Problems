#include <iostream>
#include <array>
using namespace std;

class Solution {
private:
    array<int,26> letters;
    
    bool compare()
    {
        for(int i=0;i<26;i++)
        {
            if(letters[i]!=0) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        bool solution = false;
        int sz1 = s1.size();
        int sz2 = s2.size();
        if(sz2<sz1) return false;
        for(int i=0;i<sz1;i++)
        {
            letters[s1[i]-'a']--;
            letters[s2[i]-'a']++;
        }
        if(compare()) return true;
        for(int i=sz1;i<sz2;i++)
        {
            letters[s2[i-sz1]-'a']--;
            letters[s2[i]-'a']++;
            if(compare()) return true;
        }
        return false;
    }
};