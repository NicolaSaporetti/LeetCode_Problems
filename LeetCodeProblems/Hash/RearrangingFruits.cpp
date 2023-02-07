#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<long long, long long> m = setupMap(basket1,basket2);
        int tot = 0;
        long long elementToMove = 0;
        for(auto& e : m)
        {
            if(e.second%2==1) return -1;
            tot+=e.second;
            if(e.second>0) elementToMove+=e.second;
        }
        if(tot!=0) return -1;
        elementToMove/=2;
        auto it=m.begin();
        long long res = 0;
        while(elementToMove>0)
        {
            int elementMoved = min(elementToMove,abs(it->second)/2);
            res+=elementMoved*min(2*minVal,it->first);
            elementToMove-=elementMoved;
            it++;
        }
        return res;
    }
private:
    map<long long, long long> setupMap(vector<int>& basket1, vector<int>& basket2)
    {
        map<long long, long long> m;
        for(auto& e : basket1) m[e]++;
        for(auto& e : basket2) m[e]--;
        minVal = m.begin()->first;
        for(auto it = m.begin();it!=m.end();)
        {
            if(it->second==0) m.erase(it++);
            else it++;
        }
        return m;
    }

    long long minVal;
};