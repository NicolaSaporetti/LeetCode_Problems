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