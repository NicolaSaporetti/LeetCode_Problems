#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int traverse(ListNode* node, ListNode* root, int n)
    {
        if(node!=nullptr)
        {
            int elem = traverse(node->next,node, n);
            elem--;
            if(elem==0)
            {
                if(root==nullptr) return INT_MAX;
                root->next = node->next;
            }
            return elem;
        }
        else
        {
            return n;
        }
    }
        
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int a = traverse(head,nullptr,n);
        if(a>1000)
        {
            if(head->next==nullptr) return nullptr;
            else return head->next;
        }
        return head;
    }
};