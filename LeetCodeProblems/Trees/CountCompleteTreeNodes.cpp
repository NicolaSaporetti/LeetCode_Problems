#include "TreeNode.cpp"
using namespace std;

class Solution {
private:
    void traverse(TreeNode* current)
    {
        if(current!=nullptr)
        {
            nodes++;
            traverse(current->left);
            traverse(current->right);
        }
    }
public:
    int countNodes(TreeNode* root) {
        nodes = 0;
        traverse(root);
        return nodes;
    }
    
    int nodes;
};