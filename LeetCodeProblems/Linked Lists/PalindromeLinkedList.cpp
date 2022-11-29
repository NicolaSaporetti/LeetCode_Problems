#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        result = true;
        first = head;
        traverse(head);
        return result;
    }
    
private:
    void traverse(ListNode* node)
    {
        if(node!=nullptr)
        {
            traverse(node->next);
            if(node->val != first->val) result = false;
            first = first->next;
        }
        else return;
    }
    
    ListNode* first;
    bool result;
};