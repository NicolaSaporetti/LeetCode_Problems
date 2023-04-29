#include <vector>
#include <map>
#include "..\DD\FenwickTreeOneBasedIndexing.cpp"
using namespace std;

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int sz = nums.size();
        long long res = 0;
        map<int,int> m;
        for(int i=0;i<sz;i++) m[nums[i]]=i+1;
        FenwickTreeOneBasedIndexing ft(sz);
        auto it = m.begin();
        int pos = 0;
        for(int i=0;i<sz;i++)
        {
            int newPos = it->second;
            if(newPos>=pos)
            {
                long long dist = -ft.sum(newPos)+ft.sum(pos)+newPos-pos;
                res+=dist;
            }
            else
            {
                long long dist = sz+newPos-pos-ft.sum(sz)+ft.sum(pos)-ft.sum(newPos);
                res+=dist;
            }
            pos=newPos;
            ft.add(it->second,1);
            it++;
        }
        return res;
    }
};