#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = new ListNode(0,head);
        temp->val=compute(temp->next);
        if(temp->val!=0) return temp;
        else return temp->next;
    }

    int compute(ListNode* cur)
    {
        int remaining = (cur->next!=nullptr)? compute(cur->next) : 0;
        int rest = (cur->val*2+remaining)/10;
        cur->val = (cur->val*2+remaining)%10;
        return rest;
    }   
};