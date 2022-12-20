#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* current = head;
        int carry = 0;
        while(true)
        {
            int value = carry;
            if(l1!=nullptr)
            {
                value+=l1->val;
                l1 = l1->next;
            }
            if(l2!=nullptr)
            {
                value+=l2->val;
                l2 = l2->next;
            }
            current->val = value % 10;
            carry = value/10;
            if(l1!=nullptr || l2!=nullptr || carry !=0)
            {
                current->next = new ListNode();
                current=current->next;
            }
            else break;
        }
        return head;
    }
};