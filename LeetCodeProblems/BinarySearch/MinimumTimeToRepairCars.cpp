#include <vector>
using namespace std;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1;
        long long h = 1e14;
        long long res = 1;
        while(l<=h)
        {
            long long mid = (h+l)/2;
            if(canRep(mid,ranks,cars))
            {
                res = mid;
                h=mid-1;
            }
            else l = mid+1;
        }
        return res;
    }
    bool canRep(long long mid, vector<int>& ranks, long long cars)
    {
        for(int i=0;i<ranks.size() && cars>0;i++)
        {
            cars-=(int)(sqrt(mid/ranks[i]));
        }
        return (cars<=0);
    }
};