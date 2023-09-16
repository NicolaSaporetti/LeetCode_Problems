#include "ListNode.cpp"
#include <vector>
using namespace std;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        ListNode* temp = head;
        int size = 0;
        while(temp!=nullptr)
        {
            size++;
            temp = temp->next;
        }
        int num = size/k;
        int rest = size-num*k;
        temp = head;
        ListNode* next = temp;
        for(int i=0;i<k;i++)
        {
            res.push_back(temp);
            int opti = (rest>0)? 1 : 0;
            for(int j=0;j<num+opti-1;j++) temp = temp->next;
            if(num+opti>0)
            {
                next = temp->next;
                temp->next = nullptr;
                temp = next;
            }
            if(rest>0) rest--;
        }
        return res;
    }
};