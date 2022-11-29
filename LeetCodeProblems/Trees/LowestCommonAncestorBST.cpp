#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = root;
        vector<TreeNode*> pAncestors;
        vector<TreeNode*> qAncestors;
        traverse(root, pAncestors, p->val);
        traverse(root, qAncestors, q->val);
        while(qAncestors.size()>pAncestors.size()) qAncestors.pop_back();
        while(pAncestors.size()>qAncestors.size()) pAncestors.pop_back();
        for(int i=qAncestors.size()-1;i>=0;i--)
        {
            if(qAncestors[i] == pAncestors[i])
            {
                result = qAncestors[i];
                break;
            }
        }
        return result;
    }
    
private:    
    void traverse(TreeNode* node, vector<TreeNode*>& vec, int val)
    {
        vec.push_back(node);
        if(node->val<val) traverse(node->right, vec, val);
        else if(node->val>val) traverse(node->left, vec, val);
    }
};