#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for(int i=0;i<words.size();i++)
        {
            bool matchFound = true;
            vector<vector<char>> wordsMatch(26,vector<char>(2,'0'));
            for(int j=0;j<words[i].size() && matchFound;j++)
            {
                if(wordsMatch[words[i][j]-'a'][0]=='0' && wordsMatch[pattern[j]-'a'][1]=='0')
                {
                    wordsMatch[words[i][j]-'a'][0] = pattern[j];
                    wordsMatch[pattern[j]-'a'][1] = words[i][j];
                }
                else if(wordsMatch[words[i][j]-'a'][0] !=pattern[j] || wordsMatch[pattern[j]-'a'][1] !=words[i][j])
                {
                    matchFound = false;
                }
            }
            if(matchFound) result.push_back(words[i]);
        }
        return result;
    }
};