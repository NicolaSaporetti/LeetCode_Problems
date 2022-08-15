#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    map<int,int> myM;
    int workers_sz;
    int jobs_sz;
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int sum = 0;
        jobs_sz = profit.size();
        workers_sz = worker.size();
        for(int i=0;i<jobs_sz;i++)
        {
            auto it = myM.find(difficulty[i]);
            if(it==myM.end())
            {
                myM.insert(make_pair(difficulty[i],profit[i]));
            }
            else
            {
                it->second = max(it->second, profit[i]);
            }
        }
        vector<int> diff(myM.size(), 0);
        vector<int> pay(myM.size(), 0);
        int j =0;
        for(auto it = myM.begin();it!=myM.end();it++)
        {
            diff[j]=it->first;
            if(j>0)
            {
                pay[j]=max(it->second,pay[j-1]);
            }
            else
            {
                pay[j]=it->second;
            }
            j++;
        }
        for(int i=0;i<workers_sz;i++)
        {
            int index = lower_bound(diff.begin(),diff.end(),worker[i])-diff.begin();
            if(index == diff.size() || diff[index]>worker[i])
            {
                index--;
            }
            if(index>=0)
            {
                sum+=pay[index];
            }
        }
        return sum;
    }