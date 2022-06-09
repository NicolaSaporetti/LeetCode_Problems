typedef struct limits
{
    int lR;
    int hR;
    int lC;
    int hC;
} Limits;

class Solution {
private:
    Limits limit;
    bool checkLimits(vector<vector<int>>& matrix, int target)
    {
        while(limit.lR!=limit.hR || limit.lC!=limit.hC)
        {
            for(int i=limit.lR;i<limit.hR;i++)
            {
                if(matrix[i][limit.hC]<target) limit.lR++;
                else if(matrix[i][limit.hC]>target) break;
                else return true;
            }
            for(int i=limit.hR;i>limit.lR;i--)
            {
                if(matrix[i][limit.lC]>target) limit.hR--;
                else if(matrix[i][limit.lC]<target) break;
                else return true;
            }
            for(int i=limit.lC;i<limit.hC;i++)
            {
                if(matrix[limit.hR][i]<target) limit.lC++;
                else if(matrix[limit.hR][i]>target) break;
                else return true;
            }
            for(int i=limit.hC;i>limit.lC;i--)
            {
                if(matrix[limit.lR][i]>target) limit.hC--;
                else if(matrix[limit.lR][i]<target) break;
                else return true;
            }
        }
        return (matrix[limit.lR][limit.lC]==target);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        limit.lR=0;
        limit.hR=matrix.size()-1;
        limit.lC=0;
        limit.hC=matrix[0].size()-1;
        return checkLimits(matrix, target);
    }
};