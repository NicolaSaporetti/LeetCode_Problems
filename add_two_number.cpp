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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* solution = new ListNode();
        ListNode* current = solution;
        int additional = 0;
        bool first = true;
        while(l1!=nullptr || l2!=nullptr || additional !=0)
        {
            int value = additional;
            if(first == true)
            {
                first = false;
            }
            else
            {
                current->next = new ListNode();
                current = current->next;
                if(current!=nullptr)
                {
                    cout<<"Here"<<endl;
                }
            }
            if(l1!=nullptr)
            {
                value+=l1->val;
                l1 = l1->next;
            }
            if(l2!=nullptr)
            {
                value+=l2->val;
                l2 = l2->next;
            }
            current->val = value % 10;
            additional = value/10;
            cout<<"l1: "<<l1<<endl;
            cout<<"l2: "<<l2<<endl;
            cout<<"additional: "<<additional<<endl;
            
        }
        return solution;
    }
};

int main()
{
    Solution solution;
    return 0;
}