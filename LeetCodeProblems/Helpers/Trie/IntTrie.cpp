#include <unordered_map>

class Trie {
public:
    Trie() : freq(0), wordFinished(false);
    {
    }
    void insert(vector<int>& word) {
        Trie* temp = this;
        for(int i=0;i<word.size();i++)
        {
            if(temp->children[word[i]]==nullptr)
            {
                temp->children[word[i]]=new Node();
            }
            temp = temp->children[word[i]];
            temp->freq++;
        }
        temp->wordFinished=true;
    }
    
    bool startsWith(vector<int>& word) {
        Trie* temp = this;
        for(int i=0;i<word.size();i++)
        {
            if(temp->children[word[i]]==nullptr) return false;
            temp = temp->children[word[i]];
        }
        return temp->wordFinished;
    }

    int search(vector<int>& word) {
        Trie* temp = this;
        int res = 0;
        for(int i=0;i<word.size();i++)
        {
            if(temp->children[word[i]]==nullptr) break;
            temp = temp->children[word[i]];
            res = temp->freq;
        }
        return res;
    }
    
    void erase(vector<int>& word) {
        Trie* temp = this;
        for(int i=0;i<word.size();i++)
        {
            temp->children[word[i]]->freq--;
            if(temp->children[word[i]]->freq==0)
            {
                temp->children[word[i]] = nullptr;
                break;
            }
        }
    }
    
    unordered_map<int,Trie*> children;
    int freq;
    bool wordFinished;
};