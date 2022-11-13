#include <iostream>
#include <vector>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

       ListNode* currCheck = head;

        for(int i = 0; i < k; i++)
        {
            if(currCheck == NULL)
                return head;

            currCheck = currCheck->next;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;

        for(int i = 0; i < k; i++)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;

        }
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};