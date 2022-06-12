#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int prev = 0;
        double total = 0;
        int i = 0;
        for(i=0;i<brackets.size() && brackets[i][0]<income;i++)
        {
            int value = brackets[i][0]-prev;
            prev = brackets[i][0];
            total += (value*brackets[i][1]);
            //cout<<total<<endl;
        }
        total += ((income-prev)*brackets[i][1]);
        //cout<<total<<endl;
        return total/100;
    }
};