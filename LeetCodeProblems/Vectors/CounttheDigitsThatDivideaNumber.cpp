#include <vector>
using namespace std;

class Solution {
public:
    int countDigits(int num) {
        vector<int> v;
        int temp = num;
        int tot = 0;
        while(temp>0)
        {
            v.push_back(temp%10);
            temp/=10;
        }
        for(auto& e : v)
        {
            if(num%e==0)tot++;
        }
        return tot;
    }
};