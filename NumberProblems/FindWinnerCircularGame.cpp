#include <iostream>
#include <set>
using namespace std;

class Solution {
private:
    set<int> myS;
public:
    int findTheWinner(int n, int k) {
        for(int i=0;i<n;i++) myS.insert(i+1);
        auto it = myS.begin();
        while(n>1)
        {
            int index = distance(myS.begin(), it);
            int finalIndex = (index+k-1)%n;
            it = myS.begin();
            it = advance(it,finalIndex);
            it = myS.erase(it);
            if(it==myS.end()) it = myS.begin();
            n--;
        }
        return *myS.begin();
    }
};