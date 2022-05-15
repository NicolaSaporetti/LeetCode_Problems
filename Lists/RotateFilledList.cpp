#include <iostream>
#include <list>
using namespace std;

class Solution {
private:
    int sz;
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
        ListNode* temphead = head;
        ListNode* temp = head;
        for(int i=0;i<sz-k-1;i++)
        {
            temp = temp->next;
        }
        head = temp->next;
        temp->next = nullptr;
        temp = head;
        for(int i=0;i<k-1;i++)
        {
            temp = temp->next;
        }
        temp->next = temphead;
        return head;
    }
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
};

int main()
{
    Solution solution;
    return 0;
}