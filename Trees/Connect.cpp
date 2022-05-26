#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<TreeNode*> levelStore;
    void traverse(TreeNode* node, int level)
    {
        if(levelStore.size()<level)
        {
            levelStore.push_back(node);
        }
        else
        {
            levelStore[level-1]->next = node;
            levelStore[level-1] = node;
        }
        if(node->left!=nullptr)
        {
            traverse(node->left,level+1);
        }
        if(node->right!=nullptr) 
        {
            traverse(node->right,level+1);
        }
    }
public:
    TreeNode* connect(TreeNode* root) {
        if(root!=nullptr)
            traverse(root,1);
        return root;
    }
};

int main()
{
    Solution solution;
    return 0;
}