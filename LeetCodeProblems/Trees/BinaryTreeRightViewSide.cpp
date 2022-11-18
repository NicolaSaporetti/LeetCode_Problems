#include <iostream>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> sol;
        if(root!=nullptr) q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* el = q.front();
                q.pop();
                if(el->left!=nullptr) q.push(el->left);
                if(el->right!=nullptr) q.push(el->right);
                if(i==n-1) sol.push_back(el->val);
            }
        }
        return sol;
    }
};