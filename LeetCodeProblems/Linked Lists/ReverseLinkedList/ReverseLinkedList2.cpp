#include <iostream>
#include <stack>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        for(int i=0;i<left-1;i++)
        {
            temp = temp->next;
        }
        for(int i=left;i<=right;i++)
        {
            myS.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        for(int i=0;i<left-1;i++)
        {
            temp = temp->next;
        }
        for(int i=left;i<=right;i++)
        {
            temp->val=myS.top();
            myS.pop();
            temp = temp->next;
        }
        return head;
    }
private:
    stack<int> myS;
};