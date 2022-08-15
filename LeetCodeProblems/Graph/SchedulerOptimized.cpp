#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <priority_queue>
using namespace std;

typedef pair<long long, long long> pi;

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long result = 0;
        arrange(tasks);
        while(!pq.empty())
        {
            pi el = pq.top();
            pq.pop();
            long long task_id = el.second;
            if(el.first>1) 
            {
                pq.push(make_pair(el.first-1,task_id));
            }
            if(lp.find(task_id)!=lp.end() && cur_pos_valid<lp[task_id])
            {
                result = max(result, lp[task_id]+1);
                s.insert(lp[task_id]);
                lp[task_id]+=(space+1);
            }
            else
            {
                s.insert(cur_pos_valid);
                lp[task_id]=cur_pos_valid+space+1;
                adjust_pos_valid();
            }
        }
        return max(cur_pos_valid, result);
    }
private:
    void arrange(vector<int>& tasks)
    {
        map<long long,long long> m;
        cur_pos_valid = 0;
        for(int i=0;i<tasks.size();i++) m[tasks[i]]++;
        for(auto it = m.begin();it!=m.end();it++)
        {
            pq.push(make_pair(it->second,it->first));
        }
    }
    void adjust_pos_valid()
    {
        do
        {
            cur_pos_valid++;
        }
        while(s.find(cur_pos_valid)!=s.end());
    }
    
    set<long long> s;
    long long cur_pos_valid;
    map<long long,long long> lp;
    priority_queue<pi> pq;
};