#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(),num.end());
        int carry = 0;
        for(int i=0;i<num.size() && (carry || k>0);i++)
        {
            int value = carry+k%10+num[i];
            carry = value/10;
            num[i]=value%10;
            k/=10;
        }
        while(carry || k>0)
        {
            int value = carry+k%10;
            carry = (value)/10;
            num.push_back(value%10);
            k/=10;
        }
        reverse(num.begin(),num.end());
        return num;
    }
};