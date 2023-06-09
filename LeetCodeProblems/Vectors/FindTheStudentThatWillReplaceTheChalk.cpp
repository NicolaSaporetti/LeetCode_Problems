#include <vector>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long tot = 0;
        for(auto &c : chalk) tot+=(long long)c;
        k = k%tot;
        for(int i=0;i<chalk.size();i++)
        {
            if(k<chalk[i]) return i;
            else k-=chalk[i];
        }
        return -1;
    }
};