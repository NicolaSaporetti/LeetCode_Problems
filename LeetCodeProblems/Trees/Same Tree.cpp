#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p!=nullptr && q==nullptr) || (p==nullptr && q!=nullptr) || (p!=nullptr && q!=nullptr && p->val!=q->val)) return false;
        else if(p!=nullptr && q!=nullptr) return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        else return true;
	}
};