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
				if(matrix[i+j-1][j-1]!=matrix[i+j][j]) return false;
			}
		}
        for(int i=1;i<cz;i++)
		{
			for(int j=1;i+j<cz && j<rz;j++)
			{
				if(matrix[j-1][i+j-1]!=matrix[j][i+j]) return false;
			}
		}
		return true;
    }
};