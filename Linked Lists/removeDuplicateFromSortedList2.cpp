#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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