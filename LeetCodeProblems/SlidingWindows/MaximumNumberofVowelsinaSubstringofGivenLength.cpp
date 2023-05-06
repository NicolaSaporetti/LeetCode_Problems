#include <vector>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0;
        vowel = 0;
        for(int i=0;i<k;i++) if(isVowel(s[i])) vowel++;
        res = max(res,vowel);
        for(int i=k;i<s.size();i++)
        {
            if(isVowel(s[i])) vowel++;
            if(isVowel(s[i-k])) vowel--;
            res = max(res,vowel);
        }
        return res;
    }
private:
    bool isVowel(char c)
    {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }

    int vowel;
};