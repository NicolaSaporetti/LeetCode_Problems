#include <vector>
using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int sz = computeSize(fruits,startPos);
        vector<int> sum = computePrefix(fruits,sz);
        int res = sum[startPos+1]-sum[startPos];
        for(int i=0;startPos+i<=sz && i<k;i++)
        {
            int right = startPos+i;
            int left = max(0,min(startPos,startPos-k+i*2));
            res = max(res,sum[right+1]-sum[left]);
        }
        for(int i=0;startPos-i>=0 && i<k;i++)
        {
            int left = startPos-i;
            int right = min(sz,max(startPos,startPos-i*2+k));
            res = max(res,sum[right+1]-sum[left]);
        }
        return res;
    }
private:
    int computeSize(vector<vector<int>>& fruits, int startPos)
    {
        int sz = 0;
        for(int i=0;i<fruits.size();i++) sz = max(sz,fruits[i][0]);
        sz = max(sz,startPos);
        return sz;
    }

    vector<int> computePrefix(vector<vector<int>>& fruits,int sz)
    {
        vector<int> sum(sz+2,0);
        int cur = 0;
        for(int i=0;i<=sz;i++)
        {
            sum[i+1]=sum[i];
            if(cur<fruits.size() && fruits[cur][0]==i) sum[i+1]+=fruits[cur++][1];
        }
        return sum;
    }
};