#include <iostream>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
private:
    vector<TreeNode*> pAncestors;
    vector<TreeNode*> qAncestors;
    bool first;
    bool found;
    
    void traverse(TreeNode* node, vector<TreeNode*>& vec, int val)
    {
        if(node!=nullptr && !found)
        {
            vec.push_back(node);
            if(node->val == val)
            {
                found = true;
                if(first) pAncestors = vec;
                else qAncestors = vec;
            }
            traverse(node->right, vec, val);
            traverse(node->left, vec, val);
            vec.pop_back();
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ancestors;
        first = true;
        found = false;
        traverse(root, ancestors, p->val);
        first = false;
        found = false;
        traverse(root, ancestors, q->val);
        while(qAncestors.size()>pAncestors.size()) qAncestors.pop_back();
        while(pAncestors.size()>qAncestors.size()) pAncestors.pop_back();
        for(int i=qAncestors.size()-1;i>=0;i--)
        {
            if(qAncestors[i]->val == pAncestors[i]->val) return qAncestors[i];
        }
        return root;
    }
};