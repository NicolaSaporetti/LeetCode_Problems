#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        if(fast==nullptr) return nullptr;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};