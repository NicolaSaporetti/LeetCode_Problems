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
    ListNode* swapPairs(ListNode* head) {
        ListNode* current = head;
        int size = 0;
        while(current!=nullptr)
        {
            size++;
            current = current->next;
        }
        current = head;
        for(int i=0;i+1<size;i+=2)
        {
            int temp = current->val;
            current->val = current->next->val;
            current = current->next;
            current->val = temp;
            current = current->next;
        }
        return head;
    }
};

int main()
{
    Solution solution;
    return 0;
}