#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, inorder, 0, inorder.size()-1, 0);
    }

private:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int l, int r, int k) {
        if(l>r) return nullptr;
        TreeNode* root = new TreeNode(preorder[k]);
        if(l==r) return root;
        
        int R;
        for(int i=l;i<=r;i++)
        {
            if(preorder[k]==inorder[i])
            {
                R=i;
                break;
            }
        }
        
        root->left = solve(preorder, inorder, l,R-1, k+1);
        root->right = solve(preorder, inorder, R+1, r, k+R-l+1);
        return root;
    }
};