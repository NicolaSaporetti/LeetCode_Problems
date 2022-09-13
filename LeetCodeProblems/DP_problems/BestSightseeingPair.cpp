#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    set<int> myS;
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int sz = values.size();
        int elem = 0;
        myS.insert(elem);
        int result = 0;
        for(int i=1;i<sz;i++)
        {
            if(values[i]+i-elem>values[elem])
            {
                myS.insert(i);
                elem = i;
            }
        }
        myS.insert(sz-1);
        int starting = *myS.begin();
        myS.erase(starting);
        for(auto it = myS.begin();it!=myS.end();it++)
        {
            for(int i=starting+1;i<=*it;i++)
            {
                result = max(result, (values[starting]+values[i]-i+starting));
            }
            starting = *it;
        }
        return result;
    }
};