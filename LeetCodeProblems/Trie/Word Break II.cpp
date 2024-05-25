#include <vector>
#include "Trie.cpp"
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        tr = new Trie();
        sz = s.size();
        for(auto w : wordDict) tr->insert(w);
        compute(0,s);
        return r;
    }
private:
    void compute(int st, string& s)
    {
        if(st>=sz)
        {
            r.push_back(t);
            r.back().pop_back();
        }
        else
        {
            Trie* temp = tr;
            int i=0;
            for(;st+i<sz;i++)
            {
                if(temp->children[s[st+i]]==nullptr) break;
                t.push_back(s[st+i]);
                temp = temp->children[s[st+i]];
                if(temp->wordFinished)
                {
                    t.push_back(' ');
                    compute(st+i+1,s);
                    t.pop_back();
                }
            }
            while(i-->0) t.pop_back();
        }
    }

    vector<string> r;
    Trie* tr;
    int sz;
    string t;
};