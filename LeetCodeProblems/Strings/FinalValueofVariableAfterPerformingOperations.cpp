#include <vector>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0;
        for(auto& e : operations)
        {
            if(e[0]=='+' || e[2]=='+') val++;
            else val--;
        }
        return val;
    }
};