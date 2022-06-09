#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool result;
    void traverse(TreeNode* node, long long int left, long long int right)
    {
        if(result)
        {
            if(static_cast<long long int>(node->val)<=left || 
               static_cast<long long int>(node->val)>=right)
            {
                result = false;
                return;
            }
            if(node->left!=nullptr)
            {
                traverse(node->left,left,static_cast<long long int>(node->val));
            }
            if(node->right!=nullptr)
            {
                traverse(node->right,static_cast<long long int>(node->val),right);
            }
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        result = true;
        if(result && root!=nullptr)
            traverse(root,-3000000000,3000000000);
        return result;
    }
};