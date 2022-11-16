#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> results;
        results.push_back({1});
        for(int i=1;i<numRows;i++)
        {
            vector<int> result;
            result.push_back(1);
            for(int j=0;j<i-1;j++) result.push_back(results[i-1][j]+results[i-1][j+1]);
            result.push_back(1);
            results.push_back(result);
        }
        return results;
    }
};