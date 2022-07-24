#include <iostream>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp1=nullptr;
        ListNode* temp2=nullptr;
        ListNode* head1=nullptr;
        ListNode* head2=nullptr;
        for(ListNode* temp = head;temp!=nullptr;temp = temp->next)
        {
            if(temp->val<x)
            {
                fillNewList(head1, temp1, temp->val);
            }
            else
            {
                fillNewList(head2, temp2, temp->val);
            }
        }
        if(head1==nullptr) return head2;
        else
        {
            temp1->next = head2;
            return head1;
        }
    }
private: 
    void fillNewList(ListNode*& head, ListNode*& temp, int val)
    {
        if(head==nullptr)
        {
            head = new ListNode(val);
            temp = head;
        }
        else
        {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
    }
};