#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        updackList(head);
        return buildTree(0,v.size()-1);
    }
private:
    void updackList(ListNode* head)
    {
        while(head!=nullptr)
        {
            v.push_back(head->val);
            head = head->next;
        }
    }

    TreeNode* buildTree(int left, int right)
    {
        if(left>right) return nullptr;
        else
        {
            int mid = (left+right)/2;
            TreeNode* root = new TreeNode(v[mid]);
            root->left = buildTree(left, mid-1);
            root->right = buildTree(mid+1,right);
            return root;
        }
    }

    vector<int> v;
};