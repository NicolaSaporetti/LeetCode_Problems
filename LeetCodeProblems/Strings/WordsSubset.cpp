#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int> letters(26,0);
        for(int i=0;i<words2.size();i++)
        {
            vector<int> lettersTemp(26,0);
            for(int j=0;j<words2[i].size();j++)
            {
                lettersTemp[words2[i][j]-'a']++;
            }
            for(int j=0;j<26;j++)
            {
                if(letters[j]<lettersTemp[j]) letters[j] = lettersTemp[j];
            }
        }
        for(int i=0;i<words1.size();i++)
        { 
            vector<int> lettersTemp(26,0);
            bool isWordASubset = true;
            for(int j=0;j<words1[i].size();j++)
            {
                lettersTemp[words1[i][j]-'a']++;
            }
            for(int j=0;j<26 && isWordASubset;j++)
            {
                if(letters[j]>lettersTemp[j]) isWordASubset = false;
            }
            if(isWordASubset) result.push_back(words1[i]);
        }
        return result;
    }
};