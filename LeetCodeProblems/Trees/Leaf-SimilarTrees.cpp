#include "TreeNode.cpp"
#include <vector>
using namespace std;

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf_value_t1;
        vector<int> leaf_value_t2;
        computeLeafValue(root1,leaf_value_t1);
        computeLeafValue(root2,leaf_value_t2);
        return equal(begin(leaf_value_t1),end(leaf_value_t1),begin(leaf_value_t2),end(leaf_value_t2));
    }
private:
    void computeLeafValue(TreeNode* root, vector<int>& leaf_values)
    {
        if(root->left ==nullptr && root->right ==nullptr) leaf_values.push_back(root->val);
        else
        {
            if(root->left!=nullptr) computeLeafValue(root->left,leaf_values);
            if(root->right!=nullptr) computeLeafValue(root->right,leaf_values);
        }
    }
};