#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* res = head;
        while(res->next!=nullptr)
        {
            ListNode* node = new ListNode(__gcd(res->val,res->next->val),res->next);
            res->next = node;
            res=res->next->next;
        }
        return head;
    }
};