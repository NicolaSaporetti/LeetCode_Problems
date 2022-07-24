#include <iostream>
#include "TreeNode.cpp"
using namespace std;

class Solution {
private:
    int traverse(TreeNode* current)
    {
        int nodes = 0;
        if(current!=nullptr)
        {
            nodes++;
            nodes+=traverse(current->left);
            nodes+=traverse(current->right);
        }
        return nodes;
    }
public:
    int countNodes(TreeNode* root) {
        return traverse(root);
    }
};