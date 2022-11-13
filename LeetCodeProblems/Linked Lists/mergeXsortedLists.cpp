#include <vector>
#include <map>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* solution = new ListNode();
        ListNode* current = solution;
        bool isfirst = true;
        map<int,vector<int>> m;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=nullptr) m[lists[i]->val].push_back(i);
        }
        if(m.empty()) return nullptr;
        do
        {
            if(isfirst==true) isfirst = false;
            else
            {
                current->next = new ListNode();      
                current = current->next; 
            }
            int val = m.begin()->first;
            int listN = m.begin()->second[m.begin()->second.size()-1];
            m.begin()->second.pop_back();
            if(m.begin()->second.size()==0) m.erase(val);
            current->val = val;
            lists[listN] = lists[listN]->next;
            if(lists[listN]!=nullptr) m[lists[listN]->val].push_back(listN);
   
        }while(!m.empty());
        return solution;
    }
};