#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while (head!=nullptr)
        {
            result*=2;
            result+=head->val;
            head = head->next;
        }
        return result;
    }
};