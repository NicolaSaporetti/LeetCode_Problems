#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
	int maxDepth(TreeNode* root) {
        maxLevel = 0;
		traverse(root, 0);
		return maxLevel;
	}
private:
	void traverse(TreeNode* p, int level)
	{
		if(p==nullptr) maxLevel = max(maxLevel, level);
        else
        {
            traverse(p->left,level+1);
            traverse(p->right,level+1);
        }
	}
    
	int maxLevel;
};