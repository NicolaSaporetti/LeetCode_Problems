#include "ListNode.cpp"
using namespace std;

class Solution {        
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        finalHead = head;
        traverse(head,nullptr,n);
        return finalHead;
    }
    
private:
    int traverse(ListNode* node, ListNode* prev, int n)
    {
        if(node!=nullptr)
        {
            int elem = traverse(node->next,node, n);
            elem--;
            if(elem==0)
            {
                if(prev==nullptr) finalHead = node->next;
                else prev->next = node->next;
            }
            return elem;
        }
        else return n;
    }
    
    ListNode* finalHead;
};