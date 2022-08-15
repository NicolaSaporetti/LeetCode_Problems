#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    map<double,vector<vector<int>>> myM;
    vector<vector<int>> result;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(int i=0;i<points.size();i++)
        {
            double distance = sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            auto it = myM.find(distance);
            if(it!=myM.end())
            {
                it->second.push_back(points[i]);
            }
            else
            {
                vector<vector<int>> temp;
                temp.push_back(points[i]);
                myM.insert(make_pair(distance,temp));
            }
        }
        for(auto it=myM.begin();it!=myM.end() && k>0; it++)
        {
            for(int i=0;i<it->second.size();i++)
            {
                result.push_back(it->second[i]);
                k--;
            }
        }
        return result;
    }
};