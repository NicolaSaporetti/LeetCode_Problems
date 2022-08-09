#include <iostream>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        result = true;
        first = head;
        traverse(head,head);
        return result;
    }
private:
    void traverse(ListNode* nodeToCheck, ListNode* fastIter)
    {
        if(fastIter!=nullptr && fastIter->next!=nullptr)
        {
            traverse(nodeToCheck->next,fastIter->next->next);
            if(nodeToCheck->val != first->val) result = false;
            first = first->next;
        }
        else return;
    }
    ListNode* first;
    bool result;
};