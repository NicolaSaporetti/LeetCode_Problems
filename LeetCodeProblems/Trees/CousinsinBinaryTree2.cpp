#include <queue>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val =0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            int sum = 0;
            for(int i=0;i<n;i++)
            {
                auto el = q.front();
                sum+=(el->left==nullptr)? 0 : el->left->val;
                sum+=(el->right==nullptr)? 0 : el->right->val;
                q.push(q.front());
                q.pop();
            }
            for(int i=0;i<n;i++)
            {
                auto el = q.front();
                q.pop();
                int left = (el->left==nullptr)? 0 : el->left->val;
                int right = (el->right==nullptr)? 0 : el->right->val;
                if(el->left!=nullptr)
                {
                    el->left->val = sum-left-right;
                    q.push(el->left);
                }
                if(el->right!=nullptr)
                {
                    el->right->val = sum-right-left;
                    q.push(el->right);
                }
            }
        }
        return root;
    }
};