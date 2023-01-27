#include <vector>
#include "SimpleTrie.cpp"
using namespace std;

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();
        vector<int> ans;
        for (string& x: words) {
            trie->insert(x);
        }
        for (string& x: words) {
            auto t = trie; int curr = 0;
            for (char& c: x) {
                curr += t->ch[c - 'a']->visited;
                t = t->ch[c - 'a'];
            }
            ans.push_back(curr);
        }
        return ans;
    }
};