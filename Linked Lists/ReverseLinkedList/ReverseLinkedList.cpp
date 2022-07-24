#include <iostream>
#include "ListNode.cpp"
using namespace std;

class Solution {
private:
    ListNode* newList;
    void traverse(ListNode* node)
    {
        if(node->next != nullptr)
        {
            traverse(node->next);
            newList->next = new ListNode(node->val);
            newList = newList->next;
        }
        else
        {
            newList->val = node->val;
        }
    }
public:
    ListNode* reverseList(ListNode* head) {
        newList = new ListNode(0);
        ListNode* headN = newList;
        if(head!=nullptr)
        {
            traverse(head);
            return headN;
        }
        else return nullptr;
    }
};