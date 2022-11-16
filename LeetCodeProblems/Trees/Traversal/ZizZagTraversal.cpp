#include <vector>
#include <queue>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> solutions;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            vector<int> sol;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* elem = q.front();
                q.pop();
                if(elem==nullptr) continue;
                sol.push_back(elem->val);
                q.push(elem->left);
                q.push(elem->right);
            }
            if(level%2==1) reverse(sol.begin(),sol.end());
            if(sol.size()>0) solutions.push_back(sol);
            level++;
        }
		return solutions;
	}
};