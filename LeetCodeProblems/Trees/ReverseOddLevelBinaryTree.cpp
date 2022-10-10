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
    
    void traverse(int level)
    {
        vector<TreeNode*> temp = move(nodes);
        if(level%2==1)
        {
            for(int i=0;i<temp.size()/2;i++)
            {
                swap(temp[temp.size()-1-i]->val,temp[i]->val);
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