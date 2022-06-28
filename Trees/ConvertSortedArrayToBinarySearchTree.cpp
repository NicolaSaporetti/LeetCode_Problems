#include <iostream>
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
    void buildTree(vector<int>& nums, int left, int right, TreeNode* node) {
        int pos = (left+right)/2;
        node->val = nums[pos];
        if(left<pos)
        {
            node->left = new TreeNode();
            buildTree(nums,left,pos-1, node->left);
        }
        else node->left = nullptr;
        if(pos<right)
        {
            node->right = new TreeNode();
            buildTree(nums,pos+1,right, node->right);
        }
        else node->right = nullptr;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = new TreeNode();
        buildTree(nums,0,nums.size()-1, root);
        return root;
    }
};