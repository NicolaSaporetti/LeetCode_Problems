#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        nodes_searched = 0;
        value = 0;
        traverse(root, k);
        return value;
    }
    
private:
    void traverse(TreeNode* node, int k)
    {
        if(node!=nullptr && nodes_searched<k)
        {
            traverse(node->left,k);
            nodes_searched++;
            if(nodes_searched==k) value = node->val;
            traverse(node->right,k);
        }
    }
    
    int nodes_searched;
    int value;
};