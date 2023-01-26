#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int rz = score.size();
        int cz = score[0].size();
        map<int,int> m;
        for(int i=0;i<rz;i++) m[score[i][k]]=i;
        vector<vector<int>> mat(rz,vector<int>(cz,0));
        int i=rz-1;
        for(auto& e : m)
        {
            for(int j=0;j<cz;j++) mat[i][j]=score[e.second][j];
            i--;
        }
        return mat;
    }
};