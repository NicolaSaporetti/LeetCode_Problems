#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
private:
    priority_queue<int> pq;
    int sz;
    
    int setup(vector<int>& target)
    {
        long long sum = 0;
        sort(target.begin(),target.end());
        sz = target.size();
        for(int i=0;i<sz;i++)
        {
            sum+=target[i];
            if(target[i]!=1) pq.push(target[i]);
        }
        return sum;
    }
public:
    bool isPossible(vector<int>& target) {
        long long sum = setup(target);
        while(!pq.empty())
        {
            long long value = pq.top();
            pq.pop();
            sum-=value;
            if(sum==0 || sum>value) return false;
            int coeff = (value-1)/sum;
            coeff = max(coeff,1);
            int newValue= value-sum*coeff;
            
            if(newValue>1)
            {
                pq.push(newValue);
                sum+=newValue;
            }
            else if(newValue==1)
            {
                sum++;
            }
            else return false;
        }
        return true;
    }
};