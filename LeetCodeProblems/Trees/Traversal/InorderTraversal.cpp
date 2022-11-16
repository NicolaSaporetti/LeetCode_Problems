#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return result;
    }
    
private:
    void traverse(TreeNode* node)
    {
        if(node!=nullptr)
        {
            traverse(node->left);
            result.push_back(node->val);
            traverse(node->right);
        }
    }
    
    vector<int> result;
};