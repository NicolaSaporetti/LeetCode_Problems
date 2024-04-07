#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int remainToVisit = rows*cols-1;
        vector<vector<int>> res;
        res.push_back({rStart,cStart});
        int dist = 1;
        while(remainToVisit>0)
        {
            for(int i=0;i<dist;i++)
            {
                cStart++;
                if(cStart<cols && cStart>=0 && rStart>=0 && rStart<rows)
                {
                    res.push_back({rStart,cStart});
                    remainToVisit--;
                }
            }
            for(int i=0;i<dist;i++)
            {
                rStart++;
                if(cStart<cols && cStart>=0 && rStart>=0 && rStart<rows)
                {
                    res.push_back({rStart,cStart});
                    remainToVisit--;
                }
            }
            dist++;
            for(int i=0;i<dist;i++)
            {
                cStart--;
                if(cStart<cols && cStart>=0 && rStart>=0 && rStart<rows)
                {
                    res.push_back({rStart,cStart});
                    remainToVisit--;
                }
            }
            for(int i=0;i<dist;i++)
            {
                rStart--;
                if(cStart<cols && cStart>=0 && rStart>=0 && rStart<rows)
                {
                    res.push_back({rStart,cStart});
                    remainToVisit--;
                }
            }
            dist++;
        }
        return res;
    }
};