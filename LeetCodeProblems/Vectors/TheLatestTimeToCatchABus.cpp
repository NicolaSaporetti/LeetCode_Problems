#include <vector>
using namespace std;

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        int n=buses.size();
        int m=passengers.size();
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        int j=0;
        int ans = 1;
        int prev = 1;
        for(int i=0;i<n;i++)
        {
            int c=0;
            while(j<m && c<capacity && passengers[j]<=buses[i])
            {
                if(passengers[j]-1!=prev)
                    ans=passengers[j]-1;
                prev=passengers[j];
                c++;
                j++;
            }
            if(c<capacity && buses[i]!=prev)
                ans=buses[i];
        }
        return ans;
    }
};