#include <vector>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> universalRequirements = buildUniversalRequirement(words2);
        vector<string> result;
        for(auto& word : words1)
        {
            vector<int> temp = createLetterAmount(word);
            if(compareVectors(temp,universalRequirements)) result.push_back(word);
        }
        return result;
    }
private:
    vector<int> buildUniversalRequirement(vector<string>& words)
    {
        vector<int> result(26,0);
        for(auto& word : words)
        {
            vector<int> temp = createLetterAmount(word);
            for(int i=0;i<26;i++) result[i] = max(result[i],temp[i]);
        }
        return result;
    }

    vector<int> createLetterAmount(string& s)
    {
        vector<int> result(26,0);
        for(auto& c : s) result[c-'a']++;
        return result;
    }

    bool compareVectors(vector<int>& word1, vector<int>& requirements)
    {
        for(int i=0;i<26;i++)
        {
            if(word1[i]<requirements[i]) return false;
        }
        return true;
    }
};