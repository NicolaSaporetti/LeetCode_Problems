#include <vector>
#include <priority_queue>
using namespace std;

struct myComp {
  bool operator() (pair<int, int> const& top_pq,
                   pair<int, int> const& new_el)
  { return top_pq.first > new_el.first || (top_pq.first==new_el.first && top_pq.second < new_el.second);}
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, myComp> pq;
        pq.push({0,0});
        vector<bool> visitedElements(amount,false);
        while(!pq.empty())
        {
            int iterations = pq.top().first+1;
            int element = pq.top().second;
            pq.pop();
            for(int i=0;i<coins.size();i++)
            {
                int value = element+coins[i];
                if(value==amount) return iterations;
                else if(value<amount && !visitedElements[value])
                {
                    visitedElements[value]=true;
                    pq.push({iterations,value});
                }
            }
        }
        return -1;
    }
};