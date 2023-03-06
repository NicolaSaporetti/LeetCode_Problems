#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serializeSubtrees(root);
        return duplicates;
    }
private:
    string serializeSubtrees(TreeNode* node) {
        if (node==nullptr) return "#";
        string left = serializeSubtrees(node->left);
        string right = serializeSubtrees(node->right);
        string s = left + "," + right + "," + to_string(node->val);
        if (subtrees[s] == 1) duplicates.push_back(node);
        subtrees[s]++;
        return s;
    }

    unordered_map<string, int> subtrees;
    vector<TreeNode*> duplicates;
};