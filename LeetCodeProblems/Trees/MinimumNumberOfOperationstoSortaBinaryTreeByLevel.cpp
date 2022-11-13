#include <queue>
#include <vector>
#include <set>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int tot = 0;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> v;
            map<int,int> s;
            for(int i=0;i<sz;i++)
            {
                TreeNode* el = q.front();
                q.pop();
                s[el->val]=i;
                v.push_back(el->val);
                if(el->left!=nullptr) q.push(el->left);
                if(el->right!=nullptr) q.push(el->right);
            }
            int j=0;
            for(auto e : s)
            {
                if(v[j]!=e.first)
                {
                    tot++;
                    s[v[j]]=e.second;
                    v[s[v[j]]]=v[j];
                }
                j++;
            }
        }
        return tot;
    }
};