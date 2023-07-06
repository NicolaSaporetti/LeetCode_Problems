#include <vector>
using namespace std;

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        bool memory = true;
        int i=1;
        for(;i<=memory1 || i<=memory2;i++)
        {
            if(memory1>=memory2) memory1-=i;
            else memory2-=i;
        }
        return {i,memory1,memory2};
    }
};