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
    vector<int> numbers;
    
    void traverse(TreeNode* node)
    {
        if(node!=nullptr)
        {
            traverse(node->left);
            numbers.push_back(node->val);
            traverse(node->right);
        }
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        traverse(root);
        int sz = numbers.size();
        for(int i=0;i<sz;i++)
        {
            if(k!=numbers[i]*2 && find(numbers.begin(),numbers.end(),k-numbers[i])!=numbers.end()) return true;
        }
        return false;
    }
};