#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
		int right = matrix.size()-1;
		int RowElem = 0;
		int ColElem = 0;
        RowElem = (left+right)/2;
		while(right!=left)
		{
			if(matrix[RowElem][0]<=target && matrix[RowElem][matrix[0].size()-1]>=target) break;
			else
			{
				if(matrix[RowElem][0]>target)
				{
					right = RowElem;
				}
				else{
					left = max(RowElem,left+1);
				}
			}
			RowElem = (left+right)/2;
		}
		left = 0;
		right = matrix[0].size()-1;
        ColElem = (left+right)/2;
		while(right!=left)
		{
			if(matrix[RowElem][ColElem]==target) break;
			else
			{
				if(matrix[RowElem][ColElem]>target)
				{
					right = ColElem;
				}
				else{
					left = max(ColElem,left+1);
				}
			}
			ColElem = (left+right)/2;
		}
		
        return matrix[RowElem][ColElem]==target;
    }
};

int main()
{
    Solution solution;
    return 0;
}