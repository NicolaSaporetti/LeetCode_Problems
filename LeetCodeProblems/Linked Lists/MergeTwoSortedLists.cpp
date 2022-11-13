#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* solution = new ListNode();
        ListNode* current = solution;
        bool isfirst = true;
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        do
        {
            if(isfirst) isfirst = false;
            else
            {
                current->next = new ListNode();      
                current = current->next; 
            }
            if(list1!=nullptr && ((list2==nullptr) || list1->val<list2->val))
            {
                current->val = list1->val;
                list1 = list1->next;
            }
            else{
                current->val = list2->val;
                list2 = list2->next;
            }     
        }while(list1!=nullptr || list2!=nullptr);
        return solution;
    }
};