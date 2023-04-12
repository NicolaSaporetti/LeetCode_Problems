#include <vector>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(),num.end());
        int carry = 0;
        for(int i=0;i<num.size() || carry || k>0;i++)
        {
            int val = (i<num.size())? num[i] : 0;
            int value = carry+k%10+val;
            carry = value/10;
            if(i<num.size()) num[i]=value%10;
            else num.push_back(value%10);
            k/=10;
        }
        reverse(num.begin(),num.end());
        return num;
    }
};