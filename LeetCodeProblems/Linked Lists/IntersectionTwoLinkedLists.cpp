#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0;
        int sizeB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(headA!=nullptr)
        {
            headA = headA->next;
            sizeA++;
        }
        while(headB!=nullptr)
        {
            headB = headB->next;
            sizeB++;
        }
        return getIntersection(tempA, tempB, sizeA, sizeB);
    }
    
private:
    ListNode* getIntersection(ListNode *headA, ListNode *headB, int sizeA, int sizeB)
    {
        while(sizeA>sizeB)
        {
            headA = headA->next;
            sizeA--;
        }
        while(sizeA<sizeB)
        {
            headB = headB->next;
            sizeB--;
        }
        while(sizeA>0)
        {
            if(headA==headB) return headA;
            else
            {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return nullptr;
    }
};