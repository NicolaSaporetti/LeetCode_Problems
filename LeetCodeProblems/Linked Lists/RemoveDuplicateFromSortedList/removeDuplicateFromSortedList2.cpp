#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        return removeDuplicate(head);
    }
    
private:
    ListNode* removeDuplicate(ListNode* current)
    {
        if(current == nullptr) return nullptr;
        else
        {
            int val = current->val;
            if(current->next==nullptr || current->next->val!=val)
            {
                current->next = removeDuplicate(current->next);
                return current;
            }
            else
            {
                while(current!=nullptr && current->val==val) current = current->next;
                return removeDuplicate(current);
            }
        }
    }
};