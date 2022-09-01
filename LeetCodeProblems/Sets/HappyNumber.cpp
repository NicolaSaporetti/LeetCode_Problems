#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> myS;
        while(n!=1)
        {
            n = computeSum(n);
            if(myS.find(n)!=myS.end()) return false;
            else myS.insert(n);
        }
        return true;
    }
    
private:
    int computeSum(int n)
    {
        int sum = 0;
        while(n>0)
        {
            sum+=pow(n%10,2);
            n/=10;
        }
        return sum;
    }
};