#include "ListNode.cpp"
#include <vector>
using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* sol = nullptr;
        while(head!=nullptr)
        {
            v.push_back(head->val);
            head=head->next;
        }
        sort(v.begin(),v.end());
        if(v.size()>0) sol = new ListNode(v[0]);
        ListNode* temp = sol;
        for(int i=1;i<v.size();i++)
        {
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }
        return sol;
    }
};