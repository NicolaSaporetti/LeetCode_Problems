#include <iostream>
#include <vector>
#include <map>
#include "TreeNode.cpp"
using namespace std;

class Solution {
private:
    map<int,int> store;
    vector<int> result;
    int max;
    void traverse(TreeNode* node)
    {
        auto it = store.insert(pair<int,int>(node->val,1));
        if(!it.second) 
        {
            auto iter = it.first;
            iter->second+=1;
            if(max<iter->second)
            {
                max = iter->second;
            }
        }
        if(node->left!=nullptr)
            traverse(node->left);
        if(node->right!=nullptr)
            traverse(node->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        max = 1;
        if(root!=nullptr)
            traverse(root);
        for(auto it=store.begin();it!=store.end();it++)
        {
            if(it->second==max)
            {
                result.push_back(it->first);
            }
        }
        return result;
    }
};