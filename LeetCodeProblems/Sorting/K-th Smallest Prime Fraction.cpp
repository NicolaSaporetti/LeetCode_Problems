#include <vector>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double,pair<int,int>>> v;
        for(int i=0;i<arr.size()-1;i++)
            for(int j=i+1;j<arr.size();j++) v.push_back({(double)arr[i]/(double)arr[j],{arr[i],arr[j]}});
        sort(begin(v),end(v));
        return {v[k-1].second.first,v[k-1].second.second};
    }
};