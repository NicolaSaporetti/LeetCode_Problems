#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isok(vector<int>dist,int speed,double hour){
        
        double taken_hour=0.0;
        for(int i=0;i<dist.size();i++){
            if(i==dist.size()-1){
                taken_hour+=(double)dist[i]/(double)speed;
            }
            else{
                taken_hour+=double(ceil((double)dist[i]/speed));
            }
        }
        return taken_hour<=hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        long long max_speed=1e9;
        long long low=1,high=max_speed;
        long long ans=-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            if(isok(dist,mid,hour)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};