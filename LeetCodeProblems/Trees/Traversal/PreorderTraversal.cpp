#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return result;
    }
    
private:
    void traverse(TreeNode* node)
    {
        if(node!=nullptr)
        {
            result.push_back(node->val);
            traverse(node->left);
            traverse(node->right);
        }
    }
    
    vector<int> result;
};