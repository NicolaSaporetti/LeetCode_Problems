#include <vector>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        vector<int> fibonacciNumber(max(n+1,3),0);
        fibonacciNumber[0]=0;
        fibonacciNumber[1]=1;
        fibonacciNumber[2]=1;
        for(int i=3;i<=n;i++) fibonacciNumber[i]=fibonacciNumber[i-1]+fibonacciNumber[i-2]+fibonacciNumber[i-3];
        return fibonacciNumber[n];
    }
};