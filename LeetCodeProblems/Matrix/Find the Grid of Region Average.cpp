#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int rz = image.size();
        int cz = image[0].size();
        vector<vector<pair<int,int>>> v(rz,vector<pair<int,int>>(cz,{0,0}));
        dx= {1,0,-1,0};
        dy={0,1,0,-1};
        for(int i=0;i<rz-2;i++)
        {
            for(int j=0;j<cz-2;j++)
            {
                if(isImage(i,j,image,threshold))
                {
                    int tot = 0;
                    for(int k=0;k<3;k++)
                        for(int y=0;y<3;y++)
                            tot+=image[i+k][j+y];
                    for(int k=0;k<3;k++)
                        for(int y=0;y<3;y++)
                        {
                            v[i+k][j+y].first++;
                            v[i+k][j+y].second+=tot/9;
                        }
                }
            }
        }
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                if(v[i][j].first!=0) image[i][j]=v[i][j].second/v[i][j].first;
            }
        }
        return image;
    }
private:
    bool isImage(int r, int c, vector<vector<int>>& image, int threshold)
    {
        for(int k=0;k<3;k++)
            for(int y=0;y<3;y++)
            {
                for(int i=0;i<4;i++)
                {
                    int rx = r+k+dx[i];
                    int ry = c+y+dy[i];
                    if(rx<r || rx>r+2 || ry<c || ry>c+2) continue;
                    if(abs(image[rx][ry]-image[r+k][c+y])>threshold) return false;
                }
            }
        return true;
    }
    
    vector<int> dx;
    vector<int> dy;
};