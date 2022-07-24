#include <iostream>
#include <vector>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* current = head;
        int size = 0;
        while(current!=nullptr)
        {
            size++;
            current = current->next;
        }
        current = head;
        for(int i=0;i+1<size;i+=2)
        {
            int temp = current->val;
            current->val = current->next->val;
            current = current->next;
            current->val = temp;
            current = current->next;
        }
        return head;
    }
};