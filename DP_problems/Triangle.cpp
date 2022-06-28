class Solution {
private:
    int row_sz;
    
    void updateWeightTriangle(vector<vector<int>>& triangle)
    {
        for(int i=1;i<row_sz;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                if(j>0 && j<i)
                {
                    triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
                }
                else if(j==0)
                {
                    triangle[i][j]+=triangle[i-1][j];
                }
                else
                {
                    triangle[i][j]+=triangle[i-1][j-1];
                }
            }
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
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        row_sz = triangle.size();
        updateWeightTriangle(triangle);
		return getMinEffort(triangle);
    }
};