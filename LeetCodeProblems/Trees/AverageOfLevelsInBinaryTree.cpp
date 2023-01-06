#include <vector>
#include <queue>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> res;
        q.push(root);
        while(!q.empty())
        {
            int num = q.size();
            double total = 0;
            for(int i=0;i<num;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                total+=curr->val;
                if(curr->left!=nullptr) q.push(curr->left);
                if(curr->right!=nullptr) q.push(curr->right);
            }
            res.push_back(total/num);
        }
        return res;
    }
};