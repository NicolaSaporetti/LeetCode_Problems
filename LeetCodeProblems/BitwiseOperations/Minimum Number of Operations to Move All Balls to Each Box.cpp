#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int sz = boxes.size();
        vector<int> res(sz,0);
        for(int i=0;i<sz;i++)
        {
            int t = 0;
            for(int j=0;j<sz;j++)
            {
                if(boxes[j]=='1') t+=abs(j-i);
            }
            res[i]=t;
        }
        return res;
    }
};