#include <vector>
using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if((double)dist.size()-1>=hour) return -1;
        int minS = 1;
        int maxS = 10000000;
        int res = 10000000;
        while(minS<=maxS)
        {
            int avgS = minS+(maxS-minS)/2;
            cout<<avgS<<endl;
            if(computeTime(dist,avgS)>hour)
            {
                minS = avgS+1;
            }
            else
            {
                res = avgS;
                maxS = avgS-1;
            }
        }
        return res;
    }
private:
    double computeTime(vector<int>& dist, int s)
    {
        double d = 0;
        for(int i=0;i<dist.size()-1;i++)
        {
            d+=dist[i]/s;
            if(dist[i]%s!=0) d++;
        }
        d+=(double)dist.back()/(double)s;
        return d;
    }
};