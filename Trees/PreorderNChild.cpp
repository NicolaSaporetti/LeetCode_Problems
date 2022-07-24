#include <iostream>
#include <vector>
#include "Node.cpp"
using namespace std;

class Solution {
private:
    vector<int> result;
    void traverse(Node* node)
    {
        result.push_back(node->val);
        for(int i=0;i<node->children.size();i++)
            traverse(node->children[i]);
    }
public:
    vector<int> preorder(Node* root) {
        if(root!=nullptr)
            traverse(root);
        return result;
    }
};