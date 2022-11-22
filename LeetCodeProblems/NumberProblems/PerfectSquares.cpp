#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<bool> visitedElements(n,false);
        while(!pq.empty())
        {
            int iterations = pq.top().first+1;
            int element = pq.top().second;
            pq.pop();
            int i = 1;
            do
            {
                int value = element+i*i;
                if(value==n) return iterations;
                else if(!visitedElements[value])
                {
                    visitedElements[value]=true;
                    pq.push({iterations,value});
                }
                i++;
            } while(element+i*i<=n);
        }
        return -1;
    }
};