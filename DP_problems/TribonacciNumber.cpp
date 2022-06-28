#include <iostream>
#include <map>
using namespace std;

class Solution {
private:
    map<int,int> fibonacciValueByNumber;
    int fibC(int n)
    {
        auto it = fibonacciValueByNumber.find(n);
        if(it!=fibonacciValueByNumber.end())
        {
            return it->second;
        }
        else
        {
            int result = fibC(n-1)+fibC(n-2)+fibC(n-3);
            fibonacciValueByNumber.insert(make_pair(n,result));
            return result;
        }
    }
public:
    int tribonacci(int n) {
        fibonacciValueByNumber.insert(make_pair(-2,0));
        fibonacciValueByNumber.insert(make_pair(-1,0));
        fibonacciValueByNumber.insert(make_pair(0,0));
        fibonacciValueByNumber.insert(make_pair(1,1));
        fibonacciValueByNumber.insert(make_pair(2,1));
        return fibC(n);
    }
};