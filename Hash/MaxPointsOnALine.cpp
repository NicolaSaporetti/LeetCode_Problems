#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef struct
{
    double der;
    double y;
} line;

struct cmp {
    bool operator()(const line& a, const line& b) const {
        bool comparison = false;
        if(a.der<b.der) return true;
        else if(a.der>b.der) return false;
        else{
            return (a.y<b.y)? true : false;
        }
    }
};

class Solution {
private:
    map<line,int,cmp> myM;
    
    void putPointsOnALine(vector<vector<int>>& points, int i, int j, map<line,int,cmp>& tempM) {
        line newLine = {0.0,0.0};
        double der = 0.0;
        if(points[i][0]-points[j][0] != 0)
        {
            newLine.der = static_cast<double>(points[i][1]-points[j][1])/static_cast<double>(points[i][0]-points[j][0]);
            newLine.y = static_cast<double>(points[i][1])-newLine.der*static_cast<double>(points[i][0]);
        }
        else
        {
            newLine.der = 1000000;
            newLine.y = static_cast<double>(points[i][0]);
        }
        auto it=tempM.find(newLine);
        if(it!=tempM.end())
        {
            it->second++;
        }
        else
        {
            tempM.insert(make_pair(newLine,2));
        }
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int result = 0;
        if(points.size()==1) return 1;
        for(int i=0;i<points.size()-1;i++)
        {
            map<line,int,cmp> tempM;
            for(int j=i+1;j<points.size();j++)
            {
                putPointsOnALine(points,i,j,tempM);
            }
            for(auto it=tempM.begin();it!=tempM.end();it++)
            {
                if(myM.find(it->first)==myM.end())
                {
                    myM.insert(make_pair(it->first,it->second));
                }
            }
        }
        for(auto it=myM.begin();it!=myM.end();it++)
        {
            result = max(result,it->second);
        }
        return result;
    }
};