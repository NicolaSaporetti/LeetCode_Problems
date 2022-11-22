#include <vector>

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
        word.push_back('.');
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
        word.push_back('.');
        return startsWith(word);
    }
    
    bool startsWith(string prefix) {
        Node<char>* temp = root;
        for(int i=0;i<prefix.size();i++)
        {
            bool nodeFound = false;
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
        return true;
    }
    
private:    
    Node<char>* root;
};