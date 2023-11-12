#include <vector>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        cout<<tasks.size()<<endl;
        sort(begin(tasks),begin(tasks)+tasks.size()-1,[&](const vector<int> t1, const vector<int> t2){cout<<t2[1]<<" "<<t2[0]<<" "<<t1[1]<<" "<<t1[0]<<endl;
                                                                                      return (t2[1]-t2[0])<(t1[1]-t1[0]) || ((t2[1]-t2[0])==(t1[1]-t1[0]) && t2[1]<=t1[1]);});
        int ce = 0;
        int res = 0;
        int t = 0;
        for(int i=0;i<tasks.size();i++)
        {
            int re = max(tasks[i][1],ce);
            res = max(res,t+re);
            t+=tasks[i][0];
            ce-=tasks[i][0];
        }
        return res;       
    }
};