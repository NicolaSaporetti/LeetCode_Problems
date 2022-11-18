#include <vector>
#include "TreeNode.cpp"
using namespace std;

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        traverse(root);
        cur = 0;
    }
    
    int next() {
        return v[cur++];
    }
    
    bool hasNext() {
        return (cur<v.size())? true : false;
    }
    
private:
    void traverse(TreeNode* node)
    {
        if(node!=nullptr)
        {
            traverse(node->left);
            v.push_back(node->val);
            traverse(node->right);
        }
    }
    
    vector<int> v;
    int cur;
};