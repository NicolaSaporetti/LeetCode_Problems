using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int minv = 1;
        int maxv = 1e9;
        int res = minv;
        while(minv<=maxv)
        {
            int avg = minv +(maxv-minv)/2;
            if(computeSum(avg,n,index)<=(long long)maxSum)
            {
                res = avg;
                minv= avg+1;
            }
            else maxv = avg-1;
        }
        return res;
    }
    long long computeSum(long long avg, long long n, long long index)
    {
        long long sum = avg+(avg-1)*avg;
        if(index<avg-1) sum-=((avg-index-1)*(avg-index))/2;
        else sum+=(index-avg+1);
        if(n-index-1<avg-1) sum-=((avg+index-n)*(avg+index-n+1))/2;
        else sum+=(n-index-avg);
        return sum;
    }
};