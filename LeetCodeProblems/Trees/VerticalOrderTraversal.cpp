#include <vector>
#include <map>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root,0,0);
        for(auto i=temp.begin();i!=temp.end();i++)
        {
            vector<int> levelV;
            for(auto j=i->second.begin();j!=i->second.end();j++)
            {
                sort(j->second.begin(),j->second.end());
                for(int k=0;k<j->second.size();k++)
                {
                    levelV.push_back(j->second[k]);
                }
            }
            sol.push_back(levelV);
        }
        return sol;
    }
private:
    void traverse(TreeNode* node, int val, int level)
    {
        if(node!=nullptr)
        {
            temp[val][level].push_back(node->val);
            traverse(node->left,val-1,level+1);
            traverse(node->right,val+1,level+1);
        }
    }
    
    vector<vector<int>> sol;
    map<int,map<int,vector<int>>> temp;
};