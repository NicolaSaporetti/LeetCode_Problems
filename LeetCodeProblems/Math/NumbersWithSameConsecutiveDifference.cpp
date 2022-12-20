#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        temp.assign(n,0);
        computeNumbers(0,k);
        return sol;
    }
private:
    void computeNumbers(int pos, int dist)
    {
        if(pos == 0)
        {
            for(int i=1;i<10;i++)
            {
                temp[pos]=i;
                computeNumbers(pos+1,dist);
            }
        }
        else if (pos<temp.size())
        {
            if(temp[pos-1]+dist<10)
            {
                temp[pos]=temp[pos-1]+dist;
                computeNumbers(pos+1,dist);
            }
            
            if(temp[pos-1]-dist>=0 && dist!=0)
            {
                temp[pos]=temp[pos-1]-dist;
                computeNumbers(pos+1,dist);
            }
        }
        else
        {
            int val = 0;
            for(int i=0;i<temp.size();i++)
            {
                val*=10;
                val+=temp[i];
            }
            sol.push_back(val);
        }
    }
    
    vector<int> sol;
    vector<int> temp;
};