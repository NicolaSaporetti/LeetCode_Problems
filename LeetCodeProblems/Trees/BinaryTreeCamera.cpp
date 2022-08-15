#include <iostream>
#include "TreeNode.cpp"
using namespace std;

class Solution {
private:
	int numberOfCameras;
	void traverse(TreeNode* cur, TreeNode* root)
	{
        if(cur->left==nullptr && cur->right==nullptr && root!=nullptr)
        {
            cur->val = 2;
            if(root->val!=1)
            {
                root->val=1;
                numberOfCameras++;
            }
        }
        if(cur->left!=nullptr)
        {
            traverse(cur->left,cur);
        }
        if(cur->right!=nullptr)
        {
            traverse(cur->right,cur);
        }
        if(cur->val==1)
        {
            if(root!=nullptr && root->val!=1)
            {
                root->val = 2;
            }
        }
        else if(cur->val==0)
        {
            cur->val=2;
            if(root!=nullptr)
            {  
                if(root->val!=1)
                {
                    root->val = 1;
                    numberOfCameras++;
                }
            }
            else
            {
                cur->val = 1;
                numberOfCameras++;
            }
        }
	}
public:
    int minCameraCover(TreeNode* root) {
        numberOfCameras = 0;
        traverse(root, nullptr);
        return numberOfCameras;
	}
};