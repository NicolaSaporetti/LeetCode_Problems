#include <queue>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
	    vector<vector<int>> solutions;
        queue<TreeNode*> q;
        q.push(root);
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
            if(sol.size()>0) solutions.push_back(sol);
        }
		return solutions;
	}
};