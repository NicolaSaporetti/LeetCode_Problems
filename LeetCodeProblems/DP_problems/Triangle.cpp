#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        row_sz = triangle.size();
        updateWeightTriangle(triangle);
		return getMinEffort(triangle);
    }
    
private:    
    void updateWeightTriangle(vector<vector<int>>& triangle)
    {
        for(int i=1;i<row_sz;i++)
        {
            triangle[i][0]+=triangle[i-1][0];
            for(int j=1;j<i;j++) triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
            triangle[i][i]+=triangle[i-1][i-1];
        }
    }
    
    int getMinEffort(vector<vector<int>>& triangle)
    {
        int minEffort = INT_MAX;
        for(int i=0;i<row_sz;i++)
        {
            minEffort = min(minEffort,triangle[row_sz-1][i]);
        }
        return minEffort;
    }
    
    int row_sz;
};