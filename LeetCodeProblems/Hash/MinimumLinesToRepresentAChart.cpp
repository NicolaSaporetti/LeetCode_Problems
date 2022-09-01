#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int totalSeg=0;
        long long previous_price=INT_MAX;
        long long previous_time=INT_MIN;
        map<int,int> mymap;
        for(int i=0;i<stockPrices.size();i++)
        {
            mymap.insert (pair<int,int>(stockPrices[i][0],stockPrices[i][1]));
        }
        auto it2=mymap.begin();
        it2++;
        for(auto it=mymap.begin(); it2!=mymap.end();it2++,it++)
        {
            long long timeDiff = it2->first-it->first;
            long long priceDiff = it2->second-it->second;
            if(priceDiff*previous_time!=timeDiff*previous_price)
            {
                previous_price = priceDiff;
                previous_time= timeDiff;
                totalSeg++;
            }
        }
        return totalSeg;
    }
};