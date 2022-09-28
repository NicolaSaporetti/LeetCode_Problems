#include <vector>
#include "Trie.cpp"
using namespace std;

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        vector<int> ans;
        for (string& x: words) {
            auto t = &trie;
            for (char& c: x) {
                if (!t->ch[c - 'a']) t->ch[c - 'a'] = new Trie();
                t->ch[c - 'a']->visited++;
                t = t->ch[c - 'a'];
            }
        }
        for (string& x: words) {
            auto t = &trie; int curr = 0;
            for (char& c: x) {
                curr += t->ch[c - 'a']->visited;
                t = t->ch[c - 'a'];
            }
            ans.push_back(curr);
        }
        return ans;
    }
};