#include <vector>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int rz = matrix.size();
		int cz = matrix[0].size();
        for(int i=0;i<rz;i++)
		{
			for(int j=1;i+j<rz && j<cz;j++)
			{
				if(matrix[i][0]!=matrix[i+j][j]) return false;
			}
		}
        for(int i=1;i<cz;i++)
		{
			for(int j=1;i+j<cz && j<rz;j++)
			{
				if(matrix[0][i]!=matrix[j][i+j]) return false;
			}
		}
		return true;
    }
};