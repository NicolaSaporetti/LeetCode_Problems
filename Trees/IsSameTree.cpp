#include <iostream>
#include <vector>
#include <map>
#include "TreeNode.cpp"
using namespace std;

class Solution {
private:
	bool areTreesTheSame;
	void traverse(TreeNode* p, TreeNode* q)
	{
		if(areTreesTheSame)
		{
			if(p->val!=q->val)
			{
				areTreesTheSame = false;
				return;
			}
			if(p->left!=nullptr)
			{
				if(q->left!=nullptr)
				{
					traverse(p->left,q->left);
				}
				else
				{
					areTreesTheSame = false;
					return;
				}
			}
			else if(q->left!=nullptr)
			{	
				areTreesTheSame = false;
				return;
			}
			if(p->right!=nullptr)
			{
				if(q->right!=nullptr)
				{
					traverse(p->right,q->right);
				}
				else
				{
					areTreesTheSame = false;
					return;
				}
			}
			else if(q->right!=nullptr)
			{
				areTreesTheSame = false;
				return;
			}
		}
	}
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
	areTreesTheSame = true;
	if(p!=nullptr && q!=nullptr)
	{
		traverse(p,q);
		return areTreesTheSame;
	}
	if(p ==nullptr && q ==nullptr) return true;
	return false;
    }
};