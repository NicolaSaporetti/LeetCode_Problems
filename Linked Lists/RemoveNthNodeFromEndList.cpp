#include <iostream>
#include "ListNode.cpp"
using namespace std;

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