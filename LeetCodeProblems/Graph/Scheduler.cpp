#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        cur_pos_valid = 0;
        for(int i=0;i<tasks.size();i++)
        {
            if(lp.find(tasks[i])!=lp.end() && cur_pos_valid<lp[tasks[i]])
            {
                cur_pos_valid = lp[tasks[i]]+1;
                lp[tasks[i]]+=(space+1);
            }
            else
            {
                cur_pos_valid++;
                lp[tasks[i]]=cur_pos_valid+space;
            }
        }
        return cur_pos_valid;
    }
private:
    
    long long cur_pos_valid;
    map<long long,long long> lp;
};