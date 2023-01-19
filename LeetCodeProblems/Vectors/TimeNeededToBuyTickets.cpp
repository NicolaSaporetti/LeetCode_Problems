#include <vector>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0;
        for(int i=0;i<k;i++) res+=min(tickets[k],tickets[i]);
        for(int i=k+1;i<tickets.size();i++) res+=min(tickets[k]-1,tickets[i]);
        res += tickets[k];
        return res;
    }
};