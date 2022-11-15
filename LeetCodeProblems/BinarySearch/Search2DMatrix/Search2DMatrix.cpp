#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int bottom = 0;
		int up = matrix.size()-1;
        int rowSelected = 0;
		while(bottom<=up)
		{
			int mid = (bottom+up)/2;
            if(matrix[mid][0]>target) up = mid-1;
            else
            {
                rowSelected = mid;
                bottom = mid+1;
            }
		}
        int left = 0;
		int right = matrix[0].size()-1;
        int columnSelected = 0;
		while(left<=right)
		{
			int mid = (left+right)/2;
            if(matrix[rowSelected][mid]>target) right = mid-1;
            else
            {
                columnSelected = mid;
                left = mid+1;
            }
		}
		
        return matrix[rowSelected][columnSelected]==target;
    }
};