#include <vector>
using namespace std;

template<class T>
class Node {
public:
    T val;
    bool wordFinished;
    vector<Node<T>*> children;

    Node() {}

    Node(T val) : val(val) {}
};

class Trie {
public:
    Trie() {
        root = new Node<char>('*');
    }
    
    void insert(string word) {
        word.push_back('_');
        Node<char>* temp = root;
        for(int i=0;i<word.size();i++)
        {
            bool nodeFound = false;
            for(int j=0;j<temp->children.size();j++)
            {
                if(temp->children[j]->val==word[i])
                {
                    temp = temp->children[j];
                    nodeFound = true;
                    break;
                }
            }
            if(!nodeFound)
            {
                temp->children.push_back(new Node<char>(word[i]));
                temp = temp->children[temp->children.size()-1];
            }
        }
    }
    
    bool search(string word) {
        word.push_back('_');
        return startsWith(word,0,root);
    }
    
    bool startsWith(string prefix, int start, Node<char>* node) {
        Node<char>* temp = node;
        for(int i=start;i<prefix.size();i++)
        {
            bool nodeFound = false;
            if(prefix[i]!='.')
            {
                for(int j=0;j<temp->children.size();j++)
                {
                    if(temp->children[j]->val==prefix[i])
                    {
                        temp = temp->children[j];
                        nodeFound = true;
                        break;
                    }
                }
                if(!nodeFound)
                {
                    return false;
                }
            }
            else
            {
                for(int j=0;j<temp->children.size() && !nodeFound;j++)
                {
                    nodeFound|=startsWith(prefix, i+1, temp->children[j]);
                }
                return nodeFound;
            }
        }
        return true;
    }
    
private:    
    Node<char>* root;
};

class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.search(word);
    }
private:
    Trie trie;
};