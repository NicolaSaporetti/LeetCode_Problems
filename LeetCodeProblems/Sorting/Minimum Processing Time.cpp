#include <vector>
using namespace std;

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(begin(processorTime),end(processorTime));
        sort(begin(tasks),end(tasks));
        int n = processorTime.size();
        int r = 0;
        int sz = tasks.size()-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<4;j++)
            {
                r = max(r,processorTime[i]+tasks[sz-4*i-j]);
            }
        }
        return r;
    }
};