#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        traverse(root,s);
        return r;
        if(root->left==nullptr && root->right==nullptr)
        {
            string r = {char(root->val+'a')};
            return r;
        }
        else
        {
            string v1 = (root->left==nullptr)? "}" : smallestFromLeaf(root->left)+(char)(root->val+'a');
            string v2 = (root->right==nullptr)? "}" : smallestFromLeaf(root->right)+(char)(root->val+'a');
            return min(v1,v2);
        }
    }
private:
    void traverse(TreeNode* node, string& rest)
    {
        string s1 = (char)(node->val+'a')+rest;
        if(node->left==nullptr && node->right==nullptr)
        {
            r = (r=="")? s1 : min(r,s1);
        }
        else
        {
            if(node->left!=nullptr) traverse(node->left,s1);
            if(node->right!=nullptr) traverse(node->right,s1);
        }
    }
    string r;
};