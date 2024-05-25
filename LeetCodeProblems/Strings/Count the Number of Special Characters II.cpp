#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> v(58);
        vector<int> o(58);
        for(int i=0;i<word.size();i++)
        {
            if(word[i]>='A' && word[i]<='Z' && v[word[i]-'A']==false)
            {
                v[word[i]-'A'] = true;
                o[word[i]-'A'] = i;
            }
            else if(word[i]>='a' && word[i]<='z')
            {
                v[word[i]-'A'] = true;
                o[word[i]-'A'] = i;
            }
        }
        int r = 0;
        for(int i=0;i<26;i++) if(v[i] && v[i+32] && o[i]>o[i+32]) r++;
        return r;
    }
};