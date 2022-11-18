#include "ListNode.cpp"
using namespace std;

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		while(head!=nullptr && head->val==val) head = head->next;
        if(head!=nullptr)
        {
            ListNode* cur = head;
            while(cur->next!=nullptr)
            {
                if(cur->next->val==val) cur->next= cur->next->next;
                else cur = cur->next; 
            }
        }
        return head;
	}
};