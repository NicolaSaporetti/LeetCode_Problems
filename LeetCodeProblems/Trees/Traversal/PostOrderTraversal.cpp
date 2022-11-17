#include <vector>
#include "Node.cpp"
using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        traverse(root);
        return sol;
    }
    
private:
    void traverse(TreeNode* node)
    {
        if(node!=nullptr)
        {
            traverse(node->left);
            traverse(node->right);
            sol.push_back(node->val);
        }
    }
    
    vector<int> sol;
};