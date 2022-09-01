#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int startRow=0,startCol=0,endRow=n-1,endCol=m-1;
        vector<int>v;
        while(startRow<=endRow && startCol<=endCol){
            for(int i=startCol;i<=endCol;i++){
                v.push_back(matrix[startRow][i]);
            }
            startRow++;
            if(startRow>endRow){
                break;
            }
            for(int i=startRow;i<=endRow;i++){
                v.push_back(matrix[i][endCol]);
            }
            endCol--;
            if(startCol>endCol){
                break;
            }
            for(int i=endCol;i>=startCol;i--){
                v.push_back(matrix[endRow][i]);
            }
            endRow--;
            for(int i=endRow;i>=startRow;i--){
                v.push_back(matrix[i][startCol]);
            }
            startCol++;
        }
        return v;
    }
};