#include <vector>
#include <unordered_map>
using namespace std;

class Trie {
public:
    Trie()
    {
        size = INT_MAX;
        idx = -1;
    }
    void insert(string& word, int pos) {
        Trie* temp = this;
        int sz = word.size();
        if(temp->size>sz)
        {
            temp->size=sz;
            temp->idx = pos;
        }
        for(int i=word.size()-1;i>=0;i--)
        {
            if(temp->children[word[i]]==nullptr)
            {
                temp->children[word[i]]=new Trie();
            }
            temp = temp->children[word[i]];
            if(temp->size>sz)
            {
                temp->size=sz;
                temp->idx = pos;
            }
        }
    }

    int search(string& word) {
        Trie* temp = this;
        for(int i=word.size()-1;i>=0;i--)
        {
            if(temp->children[word[i]]==nullptr) break;
            temp = temp->children[word[i]];
        }
        return temp->idx;
    }
    
private:
    unordered_map<int,Trie*> children;
    int size;
    int idx;
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> res;
        Trie* t = new Trie();
        for(int i=0;i<wordsContainer.size();i++)
            t->insert(wordsContainer[i],i);
        for(int i=0;i<wordsQuery.size();i++)
            res.push_back(t->search(wordsQuery[i]));
        return res;
    }
};