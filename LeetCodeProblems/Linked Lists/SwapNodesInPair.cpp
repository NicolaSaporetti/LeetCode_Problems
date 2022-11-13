#include <vector>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* sol = head->next;
        ListNode* prev = NULL;
        while(head->next && head->next->next)
        {
            if(prev) prev->next = head->next;
            ListNode* temp = head->next->next;
            head->next->next = head;
            head->next = temp;
            prev = head;
            head = head->next;
        }
        
        if(head->next)
        {
            ListNode* temp = head->next;
            temp->next= head;
            head->next = NULL;
            if(prev) prev->next = temp;
        }
        return sol;
        
    }
};