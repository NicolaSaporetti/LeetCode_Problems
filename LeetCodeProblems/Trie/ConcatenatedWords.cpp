#include <vector>
#include "SimpleTrie.cpp"
using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        trie = new Trie();
        for(auto& w : words) trie->insert(w);
        for(auto& w : words)
        {
            found = false;
            searchConcatenated(w, 0, 0);
            if(found) res.push_back(w);
        }
        return res;
    }
private:
    void searchConcatenated(string& s, int pos, int words)
    {
        Trie* t = trie;
        for(int i=pos;i<s.size() && !found;i++)
        {
            if(t->ch[s[i]-'a'])
            {
                t = t->ch[s[i]-'a'];
                if(t->endWord)
                {
                    if(i+1==s.size())
                    {
                        if(words>0) found = true;
                    }
                    else searchConcatenated(s,i+1,words+1);
                }
            }
            else break;
        }
    }

    bool found;
    Trie* trie;
    vector<string> res;
};