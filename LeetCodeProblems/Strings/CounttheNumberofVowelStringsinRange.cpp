#include <vector>
using namespace std;

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int tot = 0;
        for(int i=left;i<=right;i++)
        {
            if(isVowel(words[i][0]) && isVowel(words[i].back())) tot++;
        }
        return tot;
    }
private:
    bool isVowel(char c)
    {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
};