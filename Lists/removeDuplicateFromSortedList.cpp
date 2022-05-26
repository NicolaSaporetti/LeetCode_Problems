#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        ListNode* previous;
        bool isDuplicated = false;
        if(head ==nullptr) return nullptr;
        while (current->next!=nullptr)
        {
            isDuplicated = false;
            cout<<"node "<<current->val<<endl;
            previous =current;
            while(current!=nullptr && current->next!=nullptr && current->val == current->next->val)
            {
                current = current->next;
                isDuplicated= true;
                cout<<"skip"<<endl;
            }
            if(isDuplicated)
            {
                if(current->next==nullptr)
                {
                    previous->next=nullptr;
                    return head;
                }
                else{
                    current = current->next;
                    previous->next=current;
                }
            }
            else current = current->next;
        }
        return head;
    }
};

int main()
{
    ListNode* l5= new ListNode(5);
    ListNode* l4= new ListNode(5,l5);
    ListNode* l3= new ListNode(4,l4);
    ListNode* l2= new ListNode(2,l3);
    ListNode* l1 = new ListNode(1,l2);
    ListNode* temp = l1;
    while(temp!=nullptr)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
    Solution solution;
    ListNode* l0 = solution.deleteDuplicates(l1);
    cout<<"ppp"<<endl;
    while(l0!=nullptr)
    {
        cout<<l0->val<<" ";
        l0=l0->next;
    }
    cout<<endl;
    return 0;
}