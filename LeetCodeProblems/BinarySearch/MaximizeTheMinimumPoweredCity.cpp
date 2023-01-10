#include <vector>
using namespace std;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        sz = stations.size();
        vector<long long> s = changeStations(stations,r);
        long long minE = *min_element(s.begin(),s.end());
        long long maxE = minE+k;
        long long res = minE;
        while(minE<=maxE)
        {
            long long medE = minE+(maxE-minE)/2;
            if(isCorrect(medE,s,r,k))
            {
                res = medE;
                minE = medE+1;
            }
            else maxE = medE-1;
        }
        return res;
    }
private:
    vector<long long> changeStations(vector<int>& stations, int r)
    {
        vector<long long> s(sz,0);
        for(int i=0;i<sz;i++)
        {
            s[max(0,i-r)]+=stations[i];
            if(i+r+1<sz) s[i+r+1]-=stations[i];
        }
        for(int i=1;i<sz;i++) s[i]+=s[i-1];
        return s;
    }
    bool isCorrect(long long val, vector<long long>& s, int r, int k)
    {
        vector<long long> addition(sz+1,0);
        long long adder = 0;
        for(int i=0;i<sz;i++)
        {
            adder+=addition[i];
            long long dif = val-(s[i]+adder);
            if(dif>0)
            {
                adder+=dif;
                k-=dif;
                addition[min(i+2*r+1,sz)]-=dif;
                if(k<0) return false;
            }
        }
        return true;
    }
    
    int sz;
};