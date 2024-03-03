#include "TreeNode.cpp"
#include <queue>
using namespace std;

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int v = -1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            v=q.front()->val;
            for(int i=0;i<n;i++)
            {
                auto el = q.front();
                q.pop();
                if(el->left!=nullptr) q.push(el->left);
                if(el->right!=nullptr) q.push(el->right);
            }
        }
        return v;
    }
};