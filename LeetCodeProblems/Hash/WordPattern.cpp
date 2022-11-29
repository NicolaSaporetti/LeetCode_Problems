#include <map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss (s);
        unordered_map<char, string> m;
        unordered_map<string, char> m2;
        string word;
        int i=0;
        while (ss >> word) {
            if(m.find(pattern[i])!=m.end() && m[pattern[i]]!=word ||
               m2.find(word)!=m2.end() && m2[word]!=pattern[i]) return false;
            else
            {
                m[pattern[i]]=word;
                m2[word]=pattern[i];
            }
            i++;
        }
        if(i<pattern.size()) return false;
        return true;
    }
};