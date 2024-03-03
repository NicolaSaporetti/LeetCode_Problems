class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool even = true;
        while(!q.empty())
        {
            int n = q.size();
            int prev = (even)? 0 : INT_MAX;
            for(int i=0;i<n;i++)
            {
                auto e = q.front();
                q.pop();
                if(e->left!=nullptr) q.push(e->left);
                if(e->right!=nullptr) q.push(e->right);
                if(e->val%2!=even) return false;
                if(even && e->val<=prev) return false;
                if(!even && e->val>=prev) return false;
                prev = e->val;
            }
            even = !even;
        }
        return true;
    }
};