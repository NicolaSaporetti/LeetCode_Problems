#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> results;
        vector<int> result;
        if(numRows>=1)
        {
            result.push_back(1);
            results.push_back(result);
        }
        if(numRows>=2)
        {
            result.push_back(1);
            results.push_back(result);
        }
        for(int i=3;i<=numRows;i++)
        {
            result.clear();
            result.push_back(1);
            for(int j=1;j<=i-2;j++) result.push_back(results[i-2][j-1]+results[i-2][j]);
            result.push_back(1);
            results.push_back(result);
        }
        return results;
    }
};