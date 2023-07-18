#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double tot = 0.0;
        map<double,vector<pair<double,double>>> num;
        for(auto& c : classes)
        {
            double n = c[0];
            double d = c[1];
            if(n==d) tot+=1;
            else num[(n+1)/(d+1)-n/d].push_back({c[0],c[1]});
        }
        for(int i=0;i<extraStudents && !num.empty();i++)
        {
            auto it = num.rbegin();
            double n = it->second.back().first+1;
            double d = it->second.back().second+1;
            it->second.pop_back();
            if(it->second.empty()) num.erase(next(it).base());
            num[(n+1)/(d+1)-n/d].push_back({n,d});
        }
        for(auto& [k,v] : num)
            for(auto& e : v) tot+=(e.first/e.second);
        return tot/classes.size();
    }
};