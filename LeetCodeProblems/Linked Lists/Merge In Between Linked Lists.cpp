#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head = list1;
        ListNode* t = head;
        for(int i=0;i<a-1;i++) t = t->next;
        ListNode* t1 = t;
        for(int i=a;i<=b;i++) t = t->next;
        t1->next =list2;
        while(list2->next!=nullptr) list2=list2->next;
        list2->next=t->next;
        auto t2= head;
        while(t2!=nullptr)
        {
            cout<<t2->val<<" ";
            t2=t2->next;
        }
        return head;
    }
};