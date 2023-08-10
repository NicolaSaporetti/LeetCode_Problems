#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(begin(items),end(items));
        set<int> s;
        val = 0;
        sets = 0;
        for(int i=items.size()-1;i>=0;i--)
        {
            if(k>0 && s.find(items[i][1])==s.end())
            {
                chosen.push_back(items[i][0]);
                val+=items[i][0];
                k--;
                s.insert(items[i][1]);
            }
            else left[items[i][0]]++;
        }
        val+=(s.size()*s.size());
        sets=s.size();
        return computeRemaining(k);
    }
private:
    long long computeRemaining(int k)
    {
        auto it = left.rbegin();
        int pos = chosen.size()-1;
        while(it!=left.rend())
        {
            for(int i=0;i<it->second;i++)
            {
                if(k>0)
                {
                    val+=(long long)it->first;
                    k--;
                }
                else
                {
                    long long setdif = (sets>1)? sets*sets-(sets-1)*(sets-1) : 0;
                    long long dif = it->first-chosen[pos]-setdif;
                    if(dif>0)
                    {
                        val+=dif;
                        sets--;
                        pos--;
                    }
                    else return val;
                }
            }
            it++;
        }
        return val;
    }
    
    vector<long long> chosen;
    map<long long,int> left;
    long long val;
    long long sets;
};