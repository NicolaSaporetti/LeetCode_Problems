#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		int rz = matrix.size();
		int cz = matrix[0].size();
	    set<int> Zrows;
        set<int> Zcolumns;
		for(int i=0;i<rz;i++)
		{
			for(int j=0;j<cz;j++)
			{
				if(!matrix[i][j])
                {
                    Zrows.insert(i);
                    Zcolumns.insert(j);
                }
			}
		}
		for(auto r : Zrows)
		{
			for(int j=0;j<cz;j++)
			{
				matrix[r][j]=0;
			}
		}
		for(auto c : Zcolumns)
		{
			for(int j=0;j<rz;j++)
			{
				matrix[j][c]=0;
			}
		}
    }
};