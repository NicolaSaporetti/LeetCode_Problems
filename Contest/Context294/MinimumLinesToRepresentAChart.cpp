#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
int minimumLines(vector<vector<int>>& stockPrices) {
        int totalSeg=0;
        int previous_der=INT_MAX;
        int previous_mod=0;
        map<int,int> mymap;
        for(int i=0;i<stockPrices.size();i++)
        {
            mymap.insert (pair<int,int>(stockPrices[i][0],stockPrices[i][1]));
        }
        auto It2=mymap.begin();
        It2++;
        for(auto It=mymap.begin();It2!=mymap.end();It2++,It++)
        {
            int timeDiff = It2->first-It->first;
            int priceDiff = It2->second-It->second;
            double newDer =static_cast<double>(priceDiff)/static_cast<double>(timeDiff);
            int newMod =priceDiff%timeDiff;
            if(previous_der!=newDer || previous_mod!=newMod)
            {
                previous_der=newDer;
                previous_mod=newMod;
                totalSeg++;
            }
        }
        return totalSeg;
    }
};

int main()
{
    vector<vector<int>> stock = {{1,1},{499999999,2},{999999998,3},{1000000000,5}};
    Solution solution;
    cout<<solution.minimumLines(stock)<<endl;
    return 0;
}