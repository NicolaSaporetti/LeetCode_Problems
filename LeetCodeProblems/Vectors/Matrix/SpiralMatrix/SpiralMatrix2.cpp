#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int startRow = 0;
        int endRow = n-1;
        int startCol = 0;
        int endCol = n-1;
        int num=1;
        while(startRow<=endRow && startCol<=endCol){
            for(int i=startCol;i<=endCol;i++) matrix[startRow][i]=num++;
            if(++startRow>endRow) break;
            for(int i=startRow;i<=endRow;i++) matrix[i][endCol]=num++;
            if(startCol>--endCol) break;
            for(int i=endCol;i>=startCol;i--) matrix[endRow][i]=num++;
            if(startRow>--endRow) break;
            for(int i=endRow;i>=startRow;i--) matrix[i][startCol]=num++;
            startCol++;
        }
        return matrix;
    }
};