#include <vector>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        vector<int> v;
        while(head!=nullptr)
        {
            v.push_back(head->val);
            head = head->next;
        }
        reverse(begin(v),end(v));
        int carry = 0;
        for(int i=0;i<v.size() || carry>0;i++)
        {
            if(i>=v.size())
            {
                v.push_back(carry);
                carry = 0;
            }
            else
            {
                int ncarry = (v[i]*2+carry)/10;
                v[i]=(v[i]*2+carry)%10;
                carry = ncarry;
            }
        }
        ListNode* h = new ListNode(v.back());
        ListNode* t = h;
        for(int i=v.size()-2;i>=0;i--)
        {
            t->next = new ListNode(v[i]);
            t = t->next;
        }
        return h;
    }
};