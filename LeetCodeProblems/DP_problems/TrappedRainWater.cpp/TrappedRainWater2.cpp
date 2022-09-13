#include <priority_queue>
#include <vector>
using namespace std;

typedef struct
{
    int i;
    int j;
} elem;

typedef pair<int, elem> pi;

struct myComp {
    bool operator ()(pi p1, pi p2)
    {
        return p1.first>p2.first;
    }
};

class Solution {
    int rows;
    int cols;
    vector<vector<int>> borderMap; //0 water, 1 border
    priority_queue<pi, vector<pi>, myComp> pq;
    int totalWater;
    int borderHeight;
    
    void initializeBorderMap(vector<vector<int>>& heightMap)
    {
        elem myE;
        borderMap.resize(rows);
        for(int i=0;i<rows;i++)
        {
            borderMap[i].resize(cols);
            for(int j=0;j<cols;j++)
            {
                if(!j || j==cols-1 || !i || i == rows-1)
                {
                    borderMap[i][j] = 1;
                    myE.i = i;
                    myE.j = j;
                    pq.push(make_pair(heightMap[i][j],myE));
                }
                else borderMap[i][j]=0;
            }
        }
    }
    
    void checkNextCell(vector<vector<int>>& heightMap, int i, int j)
    {
        if(i+1<rows && borderMap[i+1][j]==0) checkIfElementIsBorder(heightMap,i+1,j);
        if(i-1>=0 && borderMap[i-1][j]==0)   checkIfElementIsBorder(heightMap,i-1,j);
        if(j-1>=0 && borderMap[i][j-1]==0)   checkIfElementIsBorder(heightMap,i,  j-1);
        if(j+1<cols && borderMap[i][j+1]==0) checkIfElementIsBorder(heightMap,i,  j+1);
    }
    
    void countWater(vector<vector<int>>& heightMap)
    {
        elem myE;
        while(pq.size()>0)
        {
            myE = pq.top().second;
            borderHeight=pq.top().first;
            pq.pop();
            checkNextCell(heightMap, myE.i, myE.j);
        }
    }
    
    void checkIfElementIsBorder(vector<vector<int>>& heightMap, int i, int j)
    {
        borderMap[i][j] = 1;
        if(heightMap[i][j]>=borderHeight)
        {
            elem myE;
            myE.i = i;
            myE.j = j;
            pq.push(make_pair(heightMap[i][j],myE));
        }
        else
        {
            totalWater+= borderHeight-heightMap[i][j];
            checkNextCell(heightMap,i,j);
        }
    }
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        rows = heightMap.size();
        cols = heightMap[0].size();
        if(rows<3 || cols<3) return 0;
        initializeBorderMap(heightMap);
        countWater(heightMap);
        return totalWater;
    }
};