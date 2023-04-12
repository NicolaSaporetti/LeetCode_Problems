#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i1 = 0;
        int i2 = 0;
        vector<vector<int>> solutions;
        while(i1<firstList.size() && i2<secondList.size())
        {
            int start = max(firstList[i1][0],secondList[i2][0]);
            int end = min(firstList[i1][1],secondList[i2][1]);
            if(start<=end) solutions.push_back({start,end});
            if(firstList[i1][1]>=secondList[i2][1]) i2++;
            else i1++;
        }
        return solutions;
    }
};