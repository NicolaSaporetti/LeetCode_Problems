#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        int count = 0;
        for(int i=0;i<words.size();i++)
        {
            stringCount[words[i]]++;
        }
        for(auto i=stringCount.begin();i!=stringCount.end();i++)
        {
            stringByCount[i->second].push_back(i->first);
        }
        for(auto i=stringByCount.rbegin();i!=stringByCount.rend()&& count<k;i++)
        {
            for(int j=0;j<i->second.size() && count<k;j++)
            {
                res.push_back(i->second[j]);
                count++;
            }
        }
        return res;
    }
private:
    map<string,int> stringCount;
    map<int,vector<string>> stringByCount;
};