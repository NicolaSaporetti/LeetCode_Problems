#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int result = 1;
        for(int i=0;i<points.size()-1;i++)
        {
            for(int j=i+1;j<points.size();j++) putPointsOnALine(points,i,j);
        }
        for(auto e : m) result = max(result,(int)e.second.size());
        return result;
    }
    
private:
    
    void putPointsOnALine(vector<vector<int>>& points, int i, int j) {
        pair<double, double> point;
        if(points[i][0]-points[j][0] != 0)
        {
            point.first = static_cast<double>(points[i][1]-points[j][1])/static_cast<double>(points[i][0]-points[j][0]);
            point.second = static_cast<double>(points[i][1])-point.first*static_cast<double>(points[i][0]);
        }
        else
        {
            point.first = INT_MAX;
            point.second = static_cast<double>(points[i][0]);
        }
        m[point].insert(i);
        m[point].insert(j);
    }
    
    map<pair<double,double>,set<int>> m;
};