#include <vector>
#include <map>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root,0,0);
        for(auto& [key,val] : m)
        {
            vector<int> temp;
            for(auto& [key2,level]: val)
            {
                sort(begin(level),end(level));
                for(auto& e : level) temp.push_back(e);
            }
            sol.push_back(temp);
        }
        return sol;
    }
private:
    void traverse(TreeNode* node, int level, int val)
    {
        if(node!=nullptr)
        {
            m[val][level].push_back(node->val);
            traverse(node->left,level+1,val-1);
            traverse(node->right,level+1,val+1);
        }
    }
    
    vector<vector<int>> sol;
    map<int,map<int,vector<int>>> m;
};