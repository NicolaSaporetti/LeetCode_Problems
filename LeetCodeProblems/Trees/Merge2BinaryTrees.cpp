#include "TreeNode.cpp"
using namespace std;

class Solution {
private:
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* result = nullptr;
        if(root1!=nullptr || root2!=nullptr)
        {
            if(root1!=nullptr && root2!=nullptr)
            {
                result = new TreeNode(root1->val+root2->val);
                result->left = mergeTrees(root1->left,root2->left);
                result->right = mergeTrees(root1->right,root2->right);
            }
            else if(root1==nullptr && root2!=nullptr)
            {
                result = new TreeNode(root2->val);
                result->left = mergeTrees(nullptr,root2->left);
                result->right = mergeTrees(nullptr,root2->right);
            }
            else if(root1!=nullptr && root2==nullptr)
            {
                result = new TreeNode(root1->val);
                result->left = mergeTrees(root1->left,nullptr);
                result->right = mergeTrees(root1->right,nullptr);
            }
        }
        return result;
    }
};