#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        tempHead = head;
        reorderL(head,0);
    }
    
private:
    int reorderL(ListNode* current, int current_size) {
        if(current!=nullptr)
        {
            int total_size = reorderL(current->next, current_size+1);
            if(current_size>total_size/2)
            {
                ListNode* second = tempHead->next;
                tempHead->next = current;
                current->next = second;
                tempHead = second;
            }
            else if(current_size==total_size/2)
            {
                current->next = nullptr;
            }
            return total_size;
        }
        else return current_size;
    }
    
    ListNode *tempHead;
};