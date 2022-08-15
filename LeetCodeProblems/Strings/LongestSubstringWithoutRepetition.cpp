#include <iostream>
#include <vector>
using namespace std;

class Solution {
    array<int,256> letters;
    void getStartSubstringWithoutDuplicatedLetters(int& start, string& s, int i)
    {
        while(letters[s[i]]>1)
        {
            letters[s[start]]--;
            start++;
        }
    }
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int max = 0;
        for(int i=0;i<letters.size();i++) letters[i]=0;
        for(int i=0;i<s.size();i++)
        {
            letters[s[i]]++;
            getStartSubstringWithoutDuplicatedLetters(start,s,i);
            if(i-start+1>max) max = i-start+1;
        }
        return max;
    }
};