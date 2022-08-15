#include <iostream>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
private:
    vector<int> rightSide;
    int maxCurHeight;
    
    void traverse(TreeNode* current, int curLevel)
    {
        if(curLevel>maxCurHeight)
        {
            rightSide.push_back(current->val);
            maxCurHeight = curLevel;
        }
        if(current->right!=nullptr)
        {
            traverse(current->right, curLevel+1);
        }
        if(current->left!=nullptr)
        {
            traverse(current->left, curLevel+1);
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        maxCurHeight = -1;
        if(root!=nullptr) traverse(root, 0);
        return rightSide;
    }
};