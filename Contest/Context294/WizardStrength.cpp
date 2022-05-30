#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        long long int sol = 0;
        for(int i=0;i<strength.size();i++)
        {
            int minV = INT_MAX;
            long long int sum = 0;
            for(int j=i;j<strength.size();j++)
            {
                minV =min(minV,strength[j]);
                sum+=strength[j];
                sol+=(minV*sum);
                sol%=1000000007;
            }
        }
        return sol;
    }
};

int main()
{
    Solution solution;
    return 0;
}