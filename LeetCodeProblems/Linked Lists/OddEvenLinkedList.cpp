#include "Node.cpp"
using namespace std;

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return nullptr;
        {
            ListNode* odd_head = nullptr;
            ListNode* even_head = nullptr;
            ListNode* temp_odd = nullptr;
            ListNode* temp_even = nullptr;
            bool isodd = true;
            while(head!=nullptr)
            {
                if(isodd)
                {
                    setList(&odd_head,&temp_odd,head);
                }
                else
                {
                    setList(&even_head,&temp_even,head);
                }
                head = head->next;
                isodd=!isodd;
            }
            temp_odd->next = even_head;
            if(temp_even!=nullptr) temp_even->next = nullptr;
            return odd_head;
        }
    }
    
private:
    void setList(ListNode** head, ListNode** temp_head, ListNode* current)
    {
        if(*head!=nullptr)
        {
            (*temp_head)->next = current;
            *temp_head = (*temp_head)->next;
        }
        else
        {
            *head = current;
            *temp_head = *head;
        }
    }
};