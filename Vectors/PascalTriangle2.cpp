#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> results;
        vector<int> result;
        if(rowIndex>=0)
        {
            result.push_back(1);
            results.push_back(result);
        }
        if(rowIndex>=1)
        {
            result.push_back(1);
            results.push_back(result);
        }
        for(int i=2;i<=rowIndex;i++)
        {
            result.clear();
            result.push_back(1);
            for(int j=1;j<=i-1;j++) result.push_back(results[i-1][j-1]+results[i-1][j]);
            result.push_back(1);
            results.push_back(result);
        }
        return results[rowIndex];
    }
};

int main()
{
    Solution solution;
    return 0;
}