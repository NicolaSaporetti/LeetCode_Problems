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
    bool isVectorEmpty(vector<ListNode*>& lists)
    {
        bool oneNotEmpty = false;
        for(int i=0;i<lists.size() && oneNotEmpty == false;i++)
        {
            if(lists[i]!=nullptr) oneNotEmpty = true;
        }
        return oneNotEmpty;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* solution = new ListNode();
        ListNode* current = solution;
        bool first = true;
        if(isVectorEmpty(lists) == false)
        {
            return nullptr;
        }
        do
        {
            if(first==true)
            {
                first = false;
            }
            else
            {
                current->next = new ListNode();      
                current = current->next; 
            }
            int listNumber = 0;
            int min = 20000;
            for(int i=0;i<lists.size();i++)
            {
                if(lists[i]!=nullptr)
                {
                    if(lists[i]->val<min)
                    {
                        min = lists[i]->val;
                        listNumber = i;
                    }
                }
            }
            current->val = lists[listNumber]->val;
            lists[listNumber] = lists[listNumber]->next;
   
        }while(isVectorEmpty(lists) == true);
        return solution;
    }
};