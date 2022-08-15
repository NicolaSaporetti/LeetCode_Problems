#include <iostream>
using namespace std;

class Solution {
private:
    int PalindromeCount(string& s, int startPos)
    {
        int solutions = 0;
        for(int i=0;i+startPos<s.size();i++)
        {
            if(isPalindrome(s,startPos,startPos+i)) solutions++;
        }
        return solutions;
    }
    bool isPalindrome(string& s, int startPos, int endPos)
    {
        for(int i=0;i<=(endPos-startPos)/2;i++)
        {
            if(s[startPos+i]!=s[endPos-i])
            {
                return false;
            }
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        int counter = 0;
        for(int i=0;i<s.size();i++)
        {
            counter+=PalindromeCount(s,i);
        }
        return counter;
    }
};