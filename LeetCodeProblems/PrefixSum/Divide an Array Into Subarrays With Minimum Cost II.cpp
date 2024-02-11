#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        res = nums[0];
        long long r = (long long)1000000000000000;
        for(int i=1;i<=1+dist;i++) m[nums[i]]++;
        auto it = m.begin();
        for(int i=0;i<k-1;i++)
        {
            int el = it->first;
            add(el);
            if(m.count(el)==0) it++;
        }
        r = min(r,res);
        for(int i=1;i+dist<nums.size()-1;i++)
        {
            int ea = nums[i+dist+1];
            int er = nums[i];
            m[ea]++;
            if(m.count(er)>0)
            {
                m[er]--;
                if(m[er]==0) m.erase(er);
            }
            else
            {
                sub(er);
                add(m.begin()->first);
            }
            auto it = m.begin();
            auto it2 = minM.rbegin();
            if(m.size()>0 && it->first<it2->first)
            {
                add(m.begin()->first);
                m[it2->first]++;
                sub(it2->first);
            }
            r = min(r,res);
        }
        return r;
    }
private:
    void add(long long el)
    {
        minM[el]++;
        res+=el;
        m[el]--;
        if(m[el]==0) m.erase(el);
    }
    void sub(long long el)
    {
        minM[el]--;
        res-=el;
        if(minM[el]==0) minM.erase(el);
    }
    map<int,int> minM;
    map<int,int> m;
    long long res;
};