#include <vector>
using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        vector<vector<int>> v(3,vector<int>(10,0));
        int tot = 0;
        int sz = rings.size();
        for(int i=0;i<sz;i+=2)
        {
            if(rings[i]=='B') v[0][rings[i+1]-'0']=1;
            else if(rings[i]=='G') v[1][rings[i+1]-'0']=1;
            else v[2][rings[i+1]-'0']=1;
        }
        for(int i=0;i<10;i++)
        {
            if(v[0][i]==1 && v[1][i]==1 && v[2][i]==1) tot++;
        }
        return tot;
    }
};