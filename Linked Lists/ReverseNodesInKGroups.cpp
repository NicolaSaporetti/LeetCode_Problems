#include <iostream>
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
private:
    int getSize(ListNode* list)
    {
        int size = 0;
        while(list!=nullptr)
        {
            size++;
            list = list->next;
        }
        return size;
    }
    void getXNode();
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        int size = getSize(current);
        current = head;
        for(int i=0;i+k<=size;i+=k)
        {
            for(int j=0;j<k/2;j++)
            {
                int temp = current->val;
                ListNode* tempList = current;
                for(int t=j*2;t<k-1;t++) 
                {
                    tempList =tempList->next;
                }
                current->val = tempList->val;
                tempList->val= temp;
                current =current->next;
            }
            for(int j=k/2;j<k;j++) current =current->next;
        }
        return head;
    }
};