#include "TreeNode.cpp"
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        set<int> roots;
        for(auto& tree : trees) roots.insert(tree->val);
        for(auto& tree : trees)
        {
            if(tree->left!=nullptr) roots.erase(tree->left->val);
            if(tree->right!=nullptr) roots.erase(tree->right->val);
        }
        if(roots.size()!=1) return root;
        for(auto& tree : trees)
        {
            if(m.count(tree->val)==0) m[tree->val]={-1,-1};
            if(tree->left!=nullptr)
            {
                m[tree->val].first=tree->left->val;
                if(m.count(tree->left->val)==0) m[tree->left->val]={-1,-1};
            }
            if(tree->right!=nullptr)
            {
                m[tree->val].second=tree->right->val;
                if(m.count(tree->right->val)==0) m[tree->right->val]={-1,-1};
            }
        }
        root = new TreeNode(*roots.begin());
        treeValid = true;
        buildTree(root,INT_MIN,INT_MAX);
        return (treeValid && m.empty())? root : nullptr;
    }
    
    void buildTree(TreeNode* node,int left,int right)
    {
        if(!treeValid) return;
        if(node->val<=left || node->val>=right || m.count(node->val)==0)
        {
            treeValid= false;
            return;
        }
        int nodeL = m[node->val].first;
        int nodeR = m[node->val].second;
        m.erase(node->val);
        if(nodeL!=-1 && treeValid)
        {
            node->left = new TreeNode(nodeL);
            buildTree(node->left,left,min(right,node->val));
        }
        if(nodeR!=-1 && treeValid)
        {
            node->right = new TreeNode(nodeR);
            buildTree(node->right,max(left,node->val),right);
        }
    }
    
    map<int,pair<int,int>> m;
    TreeNode* root;
    bool treeValid;
};