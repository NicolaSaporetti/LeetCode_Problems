#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    int sz;
    vector<int> bloomDayOrdered;
    
    void computebloomDayOrdered(vector<int>& bloomDay)
    {
        set<int> myS;
        for(int i=0;i<sz;i++)
        {
            myS.insert(bloomDay[i]);
        }
        for(auto it=myS.begin();it!=myS.end();it++)
        {
            bloomDayOrdered.push_back(*it);
        }
    }
    
    int computeTSum(vector<int>& nums, int adjecentFlowers, int bloom) {
        int start = 0;
        int end = -1;
        int bouquet = 0;
        for(int i=0;i<sz;i++)
        {
            if(nums[i]>bloom)
            {
                end = i-1;
                bouquet+=((end-start+1)/adjecentFlowers);
                start = i+1;
            }
        }
        bouquet+=((sz-start)/adjecentFlowers);
        return bouquet;
    }
    
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        sz = bloomDay.size();
        if(m*k>sz) return -1;
        computebloomDayOrdered(bloomDay);
        int minDay = 0;
        int maxDay = bloomDayOrdered.size()-1;
        int result = (minDay+maxDay)/2;
        int bouquetsMade = 0;
        while(minDay<maxDay)
        {
            bouquetsMade = computeTSum(bloomDay,k,bloomDayOrdered[result]);
            if(bouquetsMade<m)
            {
                minDay = result+1;
            }
            else
            {
                maxDay= result;
            }
            result = (minDay+maxDay)/2;
        }
        return bloomDayOrdered[result];
    }
};