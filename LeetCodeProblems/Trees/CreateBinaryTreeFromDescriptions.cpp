#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        for(auto edge : descriptions) s.insert(edge[0]);
        for(auto edge : descriptions)
        {
            m[edge[0]].resize(2);
            m[edge[0]][1-edge[2]] = edge[1];
            s.erase(edge[1]);
        }
        return createTree(*s.begin());
    }
    
    TreeNode* createTree(int val)
    {
        TreeNode* tree = new TreeNode(val);
        if(m[val].size()==2)
        {
            if(m[val][0]!=0) tree->left = createTree(m[val][0]);
            if(m[val][1]!=0) tree->right = createTree(m[val][1]);
        }
        return tree;
    }
    
    map<int,vector<int>> m;
    unordered_set<int> s;
};