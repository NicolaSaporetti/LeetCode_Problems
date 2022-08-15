#include <iostream>
#include <set>
#include <priority_queue>
using namespace std;

typedef pair<int, int> pi;

struct myComp {
  bool operator() (pair<int, int> const& a,
                   pair<int, int> const& b)
  { return a.first > b.first;}
};

class Solution {
public:
    int numSquares(int n) {
        priority_queue<pi, vector<pi>, myComp> pq;
        pq.push(make_pair(0,0));
        set<int> visitedElements;
        while(!pq.empty())
        {
            int iterations = pq.top().first;
            int element = pq.top().second;
            pq.pop();
            int i = 1;
            do
            {
                int value = element+i*i;
                if(value==n) return iterations+1;
                else if(visitedElements.find(value)==visitedElements.end())
                {
                    visitedElements.insert(value);
                    pq.push(make_pair(iterations+1,value));
                }
                i++;
            } while(element+i*i<=n);
        }
        return -1;
    }
};