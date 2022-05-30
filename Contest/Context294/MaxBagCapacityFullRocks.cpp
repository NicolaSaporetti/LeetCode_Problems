#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool digitCount(string num) {
        vector<int> vec;
        vec.resize(num.size());
        for(int i=0;i<num.size();i++)
        {
            int n = num[i]-48;
            if(n>=num.size())
            {
                return false;
            }
            else vec[num[i]-48]++;
        }
        for(int i=0;i<num.size();i++)
        {
            cout<<"Num: "<<num[i]<<" Vect: "<<vec[i]<<endl;
            if(vec[i]!=int(num[i]-48)) return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    return 0;
}