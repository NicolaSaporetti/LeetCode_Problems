#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, bool> pi;

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        sort(forbidden.begin(),forbidden.end());
        queue<pi> pos;
        int sz = x+8*b;
        vector<vector<bool>> visited(sz,vector<bool>(2,false));
        pos.push(make_pair(0,false));
        visited[0][0]=true;
        int step = 0;
        while(!pos.empty())
        {
            int elements = pos.size();
            for(int i=0;i<elements;i++)
            {
                pi elem = pos.front();
                pos.pop();
                if(elem.first == x) return step;
                int newElem = elem.first + a;
                if(newElem<sz && !visited[newElem][0] && find(forbidden.begin(),forbidden.end(),newElem)==forbidden.end())
                {
                    pos.push(make_pair(newElem,false));
                    visited[newElem][0] = true;
                }
                newElem = elem.first - b;
                if(!elem.second && newElem>=0 && !visited[newElem][1] && find(forbidden.begin(),forbidden.end(),newElem)==forbidden.end())
                {
                    pos.push(make_pair(newElem,true));
                    visited[newElem][1] = true;
                }
            }
            step++;
        }
        return -1;
    }
};