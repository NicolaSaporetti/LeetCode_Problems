#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while (current!=nullptr)
        {
            while(current->next!=nullptr && current->next->val == current->val) current->next = current->next->next;
            if(current!=nullptr) current = current->next;
        }
        return head;
    }
};