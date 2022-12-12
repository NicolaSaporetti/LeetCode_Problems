#include "Node.cpp"
using namespace std;

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd_head = nullptr;
        ListNode* even_head = nullptr;
        ListNode* temp_odd = nullptr;
        ListNode* temp_even = nullptr;
        ListNode* current = head;
        bool isodd = true;
        while(current!=nullptr)
        {
            if(isodd) setList(&odd_head, &temp_odd, current);
            else setList(&even_head, &temp_even, current);
            current = current->next;
            isodd=!isodd;
        }
        if(temp_odd!=nullptr) temp_odd->next = even_head;
        if(temp_even!=nullptr) temp_even->next = nullptr;
        return odd_head;
    }
    
private:
    void setList(ListNode** head, ListNode** temp, ListNode* current)
    {
        if(*head == nullptr) *head = current;
        else (*temp)->next = current;
        *temp = current;
    }
};