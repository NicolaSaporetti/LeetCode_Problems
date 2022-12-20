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
        stack<int> s;
        int carry = 0;
        while(!s1.empty() || !s2.empty() || carry)
        {
            int value = carry;
            if(!s1.empty())
            {
                value+=s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                value+=s2.top();
                s2.pop();
            }
            carry = value/10;
            s.push(value%10);
        }
        return createList(s);
    }
    
    ListNode* createList(stack<int>& s)
    {
        ListNode* head = new ListNode(s.top());
        s.pop();
        ListNode* temp = head;
        while(!s.empty())
        {
            temp->next = new ListNode(s.top());
            temp = temp->next;
            s.pop();
        }
        return head;
    }
};