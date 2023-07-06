#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto& q : queries)
        {
            int n=0;
            for(auto& p : points)
            {
                if(pow(abs(q[0]-p[0]),2)+pow(abs(q[1]-p[1]),2)<=pow(q[2],2)) n++;
            }
            res.push_back(n);
        }
        return res;
    }
};