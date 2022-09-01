#include <iostream>
#include <array>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        array<int,2> change = {};
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5) change[0]++;
            else if(bills[i]==10)
            {
                if(change[0]>0)
                {
                    change[0]--;
                    change[1]++;
                }
                else return false;
            }
            else
            {
                if(change[0]>0 && change[1]>0)
                {
                    change[0]--;
                    change[1]--;
                }
                else if(change[0]>2)
                {
                    change[0]-=3;
                }
                else return false;
            }
        }
        return true;
    }
};