#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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