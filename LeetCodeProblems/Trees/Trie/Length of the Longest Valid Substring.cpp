#include <vector>
#include "Trie.cpp"
using namespace std;

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        Trie trie;
        for(auto& e : forbidden) trie.insert(e);
        int res = 0;
        int s = 0;
        string t;
        for(int i=0;i<word.size();i++)
        {
            int maxS = min(i-s,9);
            for(int j=0;j<=maxS;j++)
            {
                t = word.substr(i-j,j+1);
                if(trie.search(t))
                {
                    i = max(s,i-9);
                    s=i+1;
                    break;
                }
            }
            res = max(res,i-s+1);
        }
        return res;
    }
};