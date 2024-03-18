#include "ListNode.cpp"
#include <unordered_map>
using namespace std;

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode node=ListNode(0, head);
        unordered_map<int, ListNode*> mp;
        int prefix=0;
        for(ListNode* ptr=&node; ptr!=nullptr; ptr=ptr->next){
            prefix+=(ptr->val);
            mp[prefix]=ptr;
        }
        prefix=0;
        for(ListNode* ptr=&node; ptr!=nullptr; ptr=ptr->next){
            prefix+=(ptr->val);
            ptr->next=mp[prefix]->next;
        }
        return node.next;
    }
};