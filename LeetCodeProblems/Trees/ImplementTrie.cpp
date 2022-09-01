#include "NodeTemplate.cpp"
using namespace std;

class Trie {
public:
    Trie() {
        root = new Node('*');
    }
    
    void insert(string word) {
        word.push_back('.');
        Node* temp = root;
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
                temp->children.push_back(new Node(word[i]));
                temp = temp->children[temp->children.size()-1];
            }
        }
    }
    
    bool search(string word) {
        word.push_back('.');
        return startsWith(word);
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
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
    Node* root;
};