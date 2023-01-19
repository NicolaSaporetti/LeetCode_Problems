#include <stack>
#include <queue>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        queue<int> q;
        while(head!=nullptr)
        {
            q.push(head->val);
            head = head->next;
        }
        ListNode* newL = new ListNode(q.front());
        ListNode* h2 = newL;
        q.pop();
        int l = 2;
        while(!q.empty())
        {
            if((l%2!=0 && l<=q.size()) || (l>q.size() && q.size()%2!=0))
            {
                for(int i=0;i<l && !q.empty();i++)
                {
                    newL->next = new ListNode(q.front());
                    q.pop();
                    newL = newL->next;
                }
            }
            else
            {
                stack<int> s;
                for(int i=0;i<l && !q.empty();i++)
                {
                    s.push(q.front());
                    q.pop();
                }
                while(!s.empty())
                {
                    newL->next = new ListNode(s.top());
                    s.pop();
                    newL = newL->next;
                }
            }
            l++;
        }
        return h2;
    }
};