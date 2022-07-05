#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](auto &a, auto &b){return a[1] > b[1];});
        int boxSel = 0;
        int result = 0;
        while(truckSize>0 && boxSel<boxTypes.size())
        {
            int size= min(truckSize,boxTypes[boxSel][0]);
            truckSize -=size;
            result+=(boxTypes[boxSel][1]*size);
            boxSel++;
        }
        return result;
    }
};