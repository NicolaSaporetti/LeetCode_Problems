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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* solution = new ListNode();
        ListNode* current = solution;
        bool first = true;
        if(list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }
        do
        {
            if(first==true)
            {
                first = false;
            }
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

int main()
{
    Solution solution;
    return 0;
}