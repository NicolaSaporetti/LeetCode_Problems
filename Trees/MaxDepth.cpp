#include <iostream>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
private:
	int maxLevel;
	void traverse(TreeNode* p, int level)
	{
		if(level>maxLevel) maxLevel = level;
		if(p->left!=nullptr)
		{
			traverse(p->left,level+1);
		}
		if(p->right!=nullptr)
		{
			traverse(p->right,level+1);
		}
	}
public:
	int maxDepth(TreeNode* root) {
		if(root!=nullptr)
		{
			traverse(root, 1);
		}
		return maxLevel;
	}
};