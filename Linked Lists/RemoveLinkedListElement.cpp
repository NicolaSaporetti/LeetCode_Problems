#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if(!head)return NULL;
		while(head){
			if(head->val == val)head = head->next; //taking head to first point where the value is not val
			else break;
		}
		if(!head)return NULL; // if there is no such element return NULL
		ListNode* cur = head;
		ListNode* prev = head;
		while(cur){
			if(cur->val == val){
				cur = cur->next; 
			}
			else{
				if(prev != cur) prev->next = cur; // edge condition (first)
				prev = cur;
				cur = cur->next;
			}
		}
		prev->next = cur; // set previous not equal element to NULL
		return head;
	}
};