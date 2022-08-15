#include <iostream>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        unrollList(head);
        return traverse(root,0);
    }
    
    void unrollList(ListNode* head)
    {
        while(head!=nullptr)
        {
            list.push_back(head->val+'0');
            head = head->next;
        }
    }
    
    bool traverse(TreeNode* root,int index)
    {
        if(root!=nullptr)
        {
            if(index>=tree.size()) tree.push_back(root->val+'0');
            else tree[index] = root->val+'0';
            std::size_t found = tree.find(list);
            if (found!=std::string::npos) return true;
            return traverse(root->left,index+1) || traverse(root->right,index+1);
        }
        return false;
    }
private:
    string list;
    string tree;
};