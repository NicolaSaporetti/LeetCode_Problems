#include <vector>
#include "SimpleTrie.cpp"
using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        res = 0;
        Trie* trie = new Trie();
        for(auto& w : words)
        {
            reverse(begin(w),end(w));
            trie->insert(w);
        }
        traverse(trie,0);
        return res;
    }
private:
    void traverse(Trie* trie, int sizeWord)
    {
        bool all_empty = all_of(begin(trie->ch),end(trie->ch),[](Trie* trie){return trie==nullptr;});
        if(all_empty) res+=(sizeWord+1);
        else
        {
            for(int i=0;i<26;i++) if(trie->ch[i]!=nullptr) traverse(trie->ch[i],sizeWord+1);
        }
    }

    int res;
};