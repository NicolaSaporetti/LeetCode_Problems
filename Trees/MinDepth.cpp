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
	int minLevel;
	void traverse(TreeNode* p, int level)
	{
        if(p!=nullptr && level<minLevel)
        {
            if(p->left==nullptr && p->right == nullptr)
            {
                if(minLevel>level) minLevel = level;
            }
            traverse(p->left,level+1);
            traverse(p->right,level+1);
        }
	}
public:
    int minDepth(TreeNode* root) {
        if(root!=nullptr)
        {
            minLevel = 1000000;
            traverse(root, 1);
            return minLevel;
        }
        else return 0;
	}
};