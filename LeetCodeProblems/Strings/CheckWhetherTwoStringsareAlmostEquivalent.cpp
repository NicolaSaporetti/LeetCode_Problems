#include <vector>
using namespace std;

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> v(26,0);
        int res = 0;
        for(int i=0;i<word1.size();i++)
        {
            v[word1[i]-'a']++;
            v[word2[i]-'a']--;
        }
        for(auto& e : v) if(abs(e)>3) return false;
        return true;
    }
};