#include <set>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        set<int> s;
        for(int i=0;i<n;i++) s.insert(i);
        int pos = 0;
        while(s.size()>1)
        {
            pos = (pos+k-1)%s.size();
            auto it = s.begin();
            advance(it,pos);
            s.erase(*it);
            pos%=s.size();
        }
        return *s.begin()+1;
    }
};