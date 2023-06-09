#include <priority_queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> v(s.size()+1,INT_MAX);
        v[0]=0;
        pq.push({0,0});
        while(!pq.empty())
        {
            int pos = pq.top().second;
            int left = pq.top().first;
            if(pos==s.size()) return left;
            pq.pop();
            for(int i=0;i<dictionary.size();i++)
            {
                int wz = dictionary[i].size();
                if(pos+wz<=s.size())
                {
                    bool cor = true;
                    for(int j=0;j<wz && cor;j++)
                    {
                        if(s[pos+j]!=dictionary[i][j]) cor = false;
                    }
                    if(cor && v[pos+wz]>left)
                    {
                        pq.push({left,pos+wz});
                        v[pos+wz]=left;
                    }
                }
            }
            if(v[pos+1]>left+1)
            {
                pq.push({left+1,pos+1});
                v[pos+1]=left+1;
            }
        }
        return -1;
    }
    
    vector<int> left;
    int sz;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
};