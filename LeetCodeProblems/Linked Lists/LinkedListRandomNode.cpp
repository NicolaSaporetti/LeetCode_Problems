#include <vector>
using namespace std;

class Solution {
public:
    Solution(ListNode* head) {
        srand (time(NULL));
        while(head!=nullptr)
        {
            v.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        int ind = rand()%v.size();
        return v[ind];
    }
    vector<int> v;
};