#include <vector>
#include <unordered_map>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        int max = 0;
        for(auto& e : m)
        {
            if(e.second>max)
            {
                result.clear();
                result.push_back(e.first);
                max = e.second;
            }
            else if(e.second==max) result.push_back(e.first);
        }
        return result;
    }
private:
    void traverse(TreeNode* node)
    {
        if(node!=nullptr)
        {
            m[node->val]++;
            traverse(node->left);
            traverse(node->right);
        }
    }

    unordered_map<int,int> m;
    vector<int> result;
};