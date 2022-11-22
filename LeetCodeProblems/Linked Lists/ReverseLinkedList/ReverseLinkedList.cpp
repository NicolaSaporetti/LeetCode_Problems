#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* current = head;
        ListNode* temp =current;
        ListNode* next =temp->next;
        current->next = nullptr;
        while(next!=nullptr)
        {
            temp = next;
            next = temp->next;
            temp->next = current;
            current = temp;
        }
        return current;
    }
};