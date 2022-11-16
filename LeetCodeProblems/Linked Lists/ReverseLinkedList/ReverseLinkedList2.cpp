#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==1) return invert_list(head, right-left+1);
        else
        {
            ListNode* temp = head;
            for(int i=0;i<left-2;i++) temp = temp->next;
            temp->next = invert_list(temp->next, right-left+1);
            return head;
        }
    }
private:
    ListNode* invert_list(ListNode* current, int size)
    {
        ListNode* last = current;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        for(int i=0;i<size;i++)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        last->next = current;
        return prev;
    }
};