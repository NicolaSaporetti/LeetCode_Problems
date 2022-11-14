#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        else
        {
            sz = get_size(head);
            k = k%sz;
            if(k==0) return head;
            else return rotateFilledList(head, k);
        }
    }

private:
    int get_size(ListNode* head)
    {
        ListNode* temp = head;
        int sz=0;
        while(temp!=nullptr)
        {
            temp = temp->next;
            sz++;
        }
        return sz;
    }
    ListNode* rotateFilledList(ListNode* head, int k) {
        ListNode* oldHead = head;
        ListNode* temp = head;
        for(int i=0;i<sz-k-1;i++) temp = temp->next;
        head = temp->next;
        temp->next = nullptr;
        temp = head;
        while(temp->next!=nullptr) temp = temp->next;
        temp->next = oldHead;
        return head;
    }
    
    int sz;
};