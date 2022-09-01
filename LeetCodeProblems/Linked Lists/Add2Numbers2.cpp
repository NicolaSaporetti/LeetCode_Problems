#include <iostream>
#include <vector>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1 = fillStack(l1);
        stack<int> s2 = fillStack(l2);
        return returnSum(s1,s2);
    }
private:
    stack<int> fillStack(ListNode* l)
    {
        stack<int> s;
        while(l!=nullptr)
        {
            s.push(l->val);
            l=l->next;
        }
        return s;
    }
    ListNode* returnSum(stack<int> s1, stack<int> s2)
    {
        int carry = 0;
        ListNode* current = nullptr;
        while(!s1.empty() && !s2.empty())
        {
            int value = s1.top()+s2.top()+carry;
            s1.pop();
            s2.pop();
            carry = value/10;
            setNewNode(value,&current);
        }
        while(!s1.empty())
        {
            int value = s1.top()+carry;
            s1.pop();
            carry = value/10;
            setNewNode(value,&current);
        }
        while(!s2.empty())
        {
            int value = s2.top()+carry;
            s2.pop();
            carry = value/10;
            setNewNode(value,&current);
        }
        if(carry!=0)
        {
            setNewNode(carry,&current);
        }
        return current;
    }
    
    void setNewNode(int value, ListNode** current)
    {
        ListNode* temp = new ListNode(value%10);
        temp->next=*current;
        *current = temp;
    }
};