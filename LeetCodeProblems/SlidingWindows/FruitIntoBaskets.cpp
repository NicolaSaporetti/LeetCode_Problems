#include <vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        int pF = -1;
        int pL = -1;
        int temp = 0;
        for(int i=0;i<fruits.size();i++)
        {
            if(pF==-1) pF=i;
            else
            {
                if(fruits[i]==fruits[pF]);
                else if(pL==-1 || fruits[i]==fruits[pL])
                {
                    pL = pF;
                    pF = i;
                }
                else
                {
                    res = max(res, temp);
                    temp = i-pF;
                    pL = pF;
                    pF = i;
                }
            }
            temp++;
        }
        res = max(res, temp);
        return res;
    }
};