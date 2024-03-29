#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long result = 0;
        vector<int> values(n,0);
        for(int i=0;i<roads.size();i++)
        {
            values[roads[i][0]]++;
            values[roads[i][1]]++;
        }
        sort(values.begin(),values.end());
        for(int i=0;i<values.size();i++)
        {
            result+= (values[i]*(i+1));
        }
        return result;
    }
};