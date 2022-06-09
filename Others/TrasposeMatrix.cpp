class Solution {
private:
    int rows;
    int cols;
    vector<vector<int>> result;
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        result.resize(cols);
        for(int i=0;i<cols;i++)result[i].resize(rows);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                result[j][i]=matrix[i][j];
            }
        }
        return result;
    }
};