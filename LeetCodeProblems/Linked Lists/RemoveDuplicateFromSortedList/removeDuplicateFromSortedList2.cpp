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
        do
        {
            isDuplicated = false;
            while(current!=nullptr && current->next!=nullptr && current->val == current->next->val)
            {
                current = current->next;
                isDuplicated= true;
            }
            if(isDuplicated)
            {
                current = current->next;
                if(current==nullptr) return nullptr;
                else head = current;
            }
        } while (isDuplicated);
        previous = head;
        current=current->next;
        if(current==nullptr) return head;
        while (current!=nullptr)
        {
            isDuplicated = false;
            while(current!=nullptr && current->next!=nullptr && current->val == current->next->val)
            {
                current = current->next;
                isDuplicated= true;
            }
            if(isDuplicated)
            {
                current = current->next;
            }
            else{
                previous->next = current;
                previous=current;
                current = current->next;
            }
        }
        if(isDuplicated) previous->next=nullptr;
        return head;
    }
};