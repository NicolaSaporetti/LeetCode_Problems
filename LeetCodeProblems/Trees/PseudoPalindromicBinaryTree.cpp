#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        v.assign(10,0);
        res = 0;
        if(root!=nullptr) traverse(root);
        return res;
    }
    
private:
    void traverse(TreeNode* node)
    {
        v[node->val]++;
        if(node->left == nullptr && node->right == nullptr)
        {
            int count = 0;
            for(int i=0;i<10;i++)
            {
                count+=(v[i]%2);
            }
            if(count<=1) res++;
        }
        if(node->left!=nullptr) traverse(node->left);
        if(node->right!=nullptr) traverse(node->right);
        v[node->val]--;
    }
    
    int res;
    vector<int> v;
};