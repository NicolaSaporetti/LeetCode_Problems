#include <iostream>
using namespace std;

bool myComp(int n1, int n2)
{
    int v1=0;
    int v2=0;
    int t1 = n1;
    int t2 = n2;
    while(n1>0)
    {
        v1+=n1%2;
        n1/=2;
    }
    while(n2>0)
    {
        v2+=n2%2;
        n2/=2;
    }
    return (v1<v2 || (v1==v2 && t1<t2))? true : false;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), myComp);
        return arr;
    }
};