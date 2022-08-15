#include <iostream>
#include <vector>
#include "ListNode.cpp"
using namespace std;

typedef struct
{
    bool intersectionPresent;
    int sizeA;
    int sizeB;
} Intersection;

Intersection* getLenghtAndIntPres(ListNode *headA, ListNode *headB)
{
    Intersection* myI = new Intersection();
    while(headA->next!=nullptr)
    {
        headA = headA->next;
        myI->sizeA++;
    }
    while(headB->next!=nullptr)
    {
        headB = headB->next;
        myI->sizeB++;
    }
    myI->intersectionPresent = (headA==headB)? true : false;
    return myI;
}
 
ListNode* getIntersection(ListNode *headA, ListNode *headB, Intersection* myI)
{
    if(myI->sizeA>myI->sizeB)
    {
        for(int i=0;i<myI->sizeA-myI->sizeB;i++) headA = headA->next;
    }
    else
    {
        for(int i=0;i<myI->sizeB-myI->sizeA;i++) headB = headB->next;
    }
    while(headA!=headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}
    
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        Intersection* inters = getLenghtAndIntPres(headA, headB);
        if(inters->intersectionPresent)
        {
            return getIntersection(headA, headB, inters);
        }
        else return nullptr;
    }
};