using namespace std;

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum = 0;
        int tot = 0;
        sum=min(numOnes,k);
        k-=sum;
        if(k>0)
        {
            tot = min(k,numZeros);
            k-=tot;
        }
        tot = 0;
        if(k>0)
        {
            tot = min(k,numNegOnes);
            sum-=tot;
        }
        return sum;
    }
};