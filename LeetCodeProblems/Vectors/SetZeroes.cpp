#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	int R;
	int C;
	vector<int> Zrows;
	vector<int> Zcolumns;
public:
    void setZeroes(vector<vector<int>>& matrix) {
		R = matrix.size();
		C = matrix[0].size();
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				if(!matrix[i][j])
				{
					Zrows.push_back(i);
					break;
				}
			}
		}
		for(int i=0;i<C;i++)
		{
			for(int j=0;j<R;j++)
			{
				if(!matrix[j][i])
				{
					Zcolumns.push_back(i);
					break;
				}
			}
		}
		for(int i=0;i<Zrows.size();i++)
		{
			for(int j=0;j<C;j++)
			{
				matrix[Zrows[i]][j]=0;
			}
		}
		for(int i=0;i<Zcolumns.size();i++)
		{
			for(int j=0;j<R;j++)
			{
				matrix[j][Zcolumns[i]]=0;
			}
		}
    }
};