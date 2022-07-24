#include <iostream>
#include <vector>
#include <map>
#include "TreeNode.cpp"
using namespace std;

class Solution {
private:
	bool nodeFound;
	TreeNode* value;
	TreeNode* Target;
	void traverse(TreeNode* p, TreeNode* q)
	{
		if(!nodeFound)
		{
			if(Target == p)
			{
				value = q;
				nodeFound = true;
				return;
			}
			if(p->left!=nullptr)
			{
				traverse(p->left,q->left);
			}
			if(p->right!=nullptr)
			{
				traverse(p->right,q->right);
			}
		}
	}
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        nodeFound = false;
        Target = target;
        value = nullptr;
        if(original!=nullptr && cloned!=nullptr)
        {
            traverse(original, cloned);
        }
        return value;
    }
};