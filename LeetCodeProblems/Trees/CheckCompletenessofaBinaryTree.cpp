#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool emptyDetected=false;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(emptyDetected && node != nullptr) return false;
            if(node==nullptr)
            {
                emptyDetected=true;
                continue;
            }
            q.push(node->left);
            q.push(node->right);
        }
        return true;

    }
};