#include "ListNode.cpp"
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v;
        vector<int> res = {-1,-1};
        vector<int> crit;
        while(head!=nullptr)
        {
            v.push_back(head->val);
            head = head->next;
        }
        for(int i=1;i<v.size()-1;i++)
        {
            if((v[i-1]<v[i] && v[i]>v[i+1]) || (v[i-1]>v[i] && v[i]<v[i+1])) crit.push_back(i);
        }
        if(crit.size()>=2)
        {
            res[1]=crit.back()-crit[0];
            res[0]=INT_MAX;
            for(int i=0;i<crit.size()-1;i++) res[0] = min(res[0],crit[i+1]-crit[i]);
        }
        return res;
    }
};