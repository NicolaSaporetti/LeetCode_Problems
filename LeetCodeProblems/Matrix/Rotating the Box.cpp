#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rz = box.size();
        int cz = box[0].size();
        vector<vector<char>> res(cz,vector<char>(rz,'.'));
        for(int i=0;i<rz;i++)
        {
            int la = cz-1;
            for(int j=cz-1;j>=0;j--)
            {
                if(box[i][j]=='*')
                {
                    res[j][rz-1-i]='*';
                    la = j-1;
                }
                if(box[i][j]=='#')
                {
                    res[la--][rz-1-i] = '#';
                }
            }
        }
        return res;
    }
};