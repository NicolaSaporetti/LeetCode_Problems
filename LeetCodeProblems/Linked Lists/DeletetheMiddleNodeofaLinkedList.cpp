#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr) head = nullptr;
        else if(head->next->next == nullptr) head->next = nullptr;
        else
        {
            ListNode* slow = head;
            ListNode* prev = slow;
            ListNode* fast = head;
            do
            {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            while(fast!=nullptr && fast->next!=nullptr);
            prev->next = slow->next;
        }
        return head;
    }
};