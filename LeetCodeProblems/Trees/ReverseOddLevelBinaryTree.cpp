#include "TreeNode.cpp"
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root!=nullptr)
        {
            nodes.push_back(root);
            traverse(0);
        }
        return root;
    }

private:
    void traverse(int level)
    {
        vector<TreeNode*> temp(nodes.size());
        copy(nodes.begin(),nodes.end(),temp.begin());
        nodes.clear();
        if(level%2==1)
        {
            for(int i=0;i<temp.size()/2;i++)
            {
                int val = nodes[temp.size()-1-i]->val;
                nodes[temp.size()-1-i]->val = nodes[i]->val;
                nodes[i]->val = val;
            }
        }
        if(temp[0]->right!=nullptr)
        {
            for(int i=0;i<temp.size();i++)
            {
                nodes.push_back(temp[i]->left);
                nodes.push_back(temp[i]->right);
            }
            traverse(level+1);
        }
    }
        
    vector<TreeNode*> nodes;
};