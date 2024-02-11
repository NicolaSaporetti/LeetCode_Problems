#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int dist = 0;
        int v = high;
        vector<int> r;
        while(v>0)
        {
            dist++;
            v/=10;
        }
        for(int i=0;i<dist;i++)
        {
            for(int j=1;j+dist-i<=10;j++)
            {
                int v1 = 0;
                for(int z=0;z<dist-i;z++)
                {
                    v1*=10;
                    v1+=(j+z);
                }
                if(v1>=low && v1<=high) r.push_back(v1);
            }
        }
        sort(begin(r),end(r));
        return r;
    }
};