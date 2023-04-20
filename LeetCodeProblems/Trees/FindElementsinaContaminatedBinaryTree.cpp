#include "TreeNode.cpp"
#include <unordered_set>
using namespace std;

class FindElements {
public:
    FindElements(TreeNode* root) {
        root->val= 0;
        traverse(root);
    }
    
    bool find(int target) {
        return s.count(target);
    }
private:
    void traverse(TreeNode* node)
    {
        s.insert(node->val);
        if(node->left!=nullptr)
        {
            node->left->val = node->val*2+1;
            traverse(node->left);
        }
        if(node->right!=nullptr)
        {
            node->right->val = node->val*2+2;
            traverse(node->right);
        }
    }

    unordered_set<int> s;
};