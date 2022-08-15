#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int minS = INT_MAX;
        int maxS = 0;
        double sum = 0;
        double div = salary.size();
        for(int i=0;i<div;i++)
        {
            minS = min(minS, salary[i]);
            maxS = max(maxS, salary[i]);
            sum+=salary[i];
        }
        if(maxS == minS) div--;
        else div-=2;
        sum-=maxS;
        sum-=minS;
        if(sum<=0) return 0;
        else return sum/div;
    }
};