#include <vector>
#include <map>
#include <set>
#include <priority_queue>
using namespace std;

typedef pair<int, char> pi;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int result = 0;
        arrangeTasks(tasks);
        while(!pq.empty())
        {
            pi el = pq.top();
            pq.pop();
            char task_id = el.second;
            if(el.first>1) 
            {
                pq.push(make_pair(el.first-1,task_id));
            }
            if(lp.find(task_id)!=lp.end())
            {
                int temp_pos_valid = lp[task_id];
                while(busyPositions.find(temp_pos_valid)!=busyPositions.end())
                {
                    temp_pos_valid++;
                }
                lp[task_id]=temp_pos_valid+n+1;
                busyPositions.insert(temp_pos_valid);
                result = max(result,temp_pos_valid);
            }
            else
            {
                result = max(result,cur_pos_valid);
                lp[task_id]=cur_pos_valid+n+1;
                busyPositions.insert(cur_pos_valid);
            }
            adjust_pos_valid();
        }
        return result;
    }
private:
    void arrangeTasks(vector<char>& tasks)
    {
        map<char,int> m;
        cur_pos_valid = 1;
        for(int i=0;i<tasks.size();i++) m[tasks[i]]++;
        for(auto it = m.begin();it!=m.end();it++)
        {
            pq.push(make_pair(it->second,it->first));
        }
    }
    
    void adjust_pos_valid()
    {
        while(busyPositions.find(cur_pos_valid)!=busyPositions.end())
        {
            cur_pos_valid++;
        }
    }
    
    set<int> busyPositions;
    int cur_pos_valid;
    map<char,int> lp;
    priority_queue<pi> pq;
};