#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int sz = arr.size();
        map<int,int> n;
        map<int,vector<int>> m;
        for(int i=0;i<arr.size();i++)
        {
            n[arr[i]]++;
        }
        for(auto it=n.begin();it!=n.end();it++)
        {
            m[it->second].push_back(it->first);
        }
        int result = 0;
        int total = 0;
        for(auto it=m.rbegin();it!=m.rend();it++)
        {
            for(int i=0;i<it->second.size();i++)
            {
                result++;
                total+=it->first;
                if(total>=sz/2) return result;
            }
        }
        return 0;
    }
};