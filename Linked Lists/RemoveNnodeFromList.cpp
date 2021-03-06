#include <iostream>
#include <vector>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        int size = 0;
        while(current!=nullptr)
        {
            size++;
            current = current->next;
        }
        current = head;
        if(n==1)
        {
            if(size == n) return nullptr;
            else{
                for(int i=0;i<size-2;i++)
                {
                    current = current->next;
                }
                current->next = nullptr;
            }
        }
        else if(n==size){
            head = head->next;
        }
        else {
            for(int i=0;i<size-n-1;i++)
            {
                current = current->next;
            }
            current->next = current->next->next;
        }
        return head;
    }
};