#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sz = chalk.size();
        long long sum = 0;
        for(int i=0;i<sz;i++)
        {
            sum+=chalk[i];
        }
        if(k>sum) k%=sum;
        for(int i=0;i<sz;i++)
        {
            k-=chalk[i];
            if(k<0) return i;
        }
        return 0;
    }
};