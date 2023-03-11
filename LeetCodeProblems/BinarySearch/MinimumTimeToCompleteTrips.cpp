#include <vector>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start = 0 , end = 1e14;
        long long res = end;
        while(start<=end)
        {
            long long mid = (start+end)/2;
            if(computeTrip(mid, time)>=totalTrips)
            {
                res = mid;
                end = mid -1;
            }
            else start = mid+1;
        }
        return res;
    }
private:
    long long computeTrip(long long mid, vector<int>& time)
    {
        long long total = 0;
        for(auto& el : time)
        {
            total+=mid/el;
        }
        return total;
    }
};