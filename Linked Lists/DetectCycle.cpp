#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        if(fast==nullptr || fast->next == nullptr) return nullptr;
        do
        {
            fast = fast->next->next;
            slow = slow->next;
        } while (fast!=nullptr && fast->next!=nullptr && fast!=slow);
        if(fast==nullptr || fast->next == nullptr) return nullptr;
        else
        {
            fast = head;
            while(fast!=slow)
            {
                fast= fast->next;
                slow=slow->next;
            }
        }
        return fast;
    }
};