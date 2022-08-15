#include <iostream>
#include <vector>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        ListNode* previous;
        bool isDuplicated = false;
        if(head ==nullptr) return nullptr;
        while (current->next!=nullptr)
        {
            isDuplicated = false;
            previous =current;
            while(current!=nullptr && current->next!=nullptr && current->val == current->next->val)
            {
                current = current->next;
                isDuplicated= true;
            }
            if(isDuplicated)
            {
                if(current->next==nullptr)
                {
                    previous->next=nullptr;
                    return head;
                }
                else{
                    current = current->next;
                    previous->next=current;
                }
            }
            else current = current->next;
        }
        return head;
    }
};