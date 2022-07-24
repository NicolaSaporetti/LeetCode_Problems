#include <iostream>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
private:
    vector<vector<int>> solution;
    int maxLevel;
	void checkMaxLevel(TreeNode* root, int level)
	{
		if(root == nullptr) return;
        else
        {
            if(level>maxLevel) maxLevel = level;
            checkMaxLevel(root->left,level+1);
            checkMaxLevel(root->right,level+1);
        }
	}
    void traverse(TreeNode* root, int level)
    {
        if(root == nullptr) return;
        else
        {
            solution[maxLevel-level].push_back(root->val);
            traverse(root->left,level+1);
            traverse(root->right,level+1);
        }
    }
    
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        maxLevel=0;
        checkMaxLevel(root,1);
        solution.resize(maxLevel);
        traverse(root,1);
        return solution;
    }
};