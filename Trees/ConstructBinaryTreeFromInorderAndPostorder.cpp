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
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int l, int r, int k) {
        if(l>r)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[k]);
        if(l==r)
            return root;
        
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
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, inorder, 0, inorder.size()-1, 0);
    }
};