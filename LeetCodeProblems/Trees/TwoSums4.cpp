#include <set>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        found = false;
        traverse(root,k);
        return found;
    }

private:
    void traverse(TreeNode* node,int k)
    {
        if(node!=nullptr && !found)
        {
            if(numbers.find(k-node->val)!=numbers.end()) found = true;
            else numbers.insert(node->val);
            traverse(node->left,k);
            traverse(node->right,k);
        }
    }

    set<int> numbers;
    bool found;
};