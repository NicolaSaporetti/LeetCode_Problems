#include <queue>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty())
        {
            int n = q.size();
            sum = 0;
            for(int i=0;i<n;i++)
            {
                TreeNode* el = q.front();
                q.pop();
                sum+=el->val;
                if(el->left!=nullptr) q.push(el->left);
                if(el->right!=nullptr) q.push(el->right);
            }
        }
        return sum;
    }
};