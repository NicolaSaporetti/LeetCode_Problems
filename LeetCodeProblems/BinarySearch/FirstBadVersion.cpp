#include <vector>
using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        int sol = 1;
        int leftSide = 1;
        int rightSide = n;
        while (leftSide<=rightSide)
        {
            int index=leftSide+(rightSide-leftSide)/2;
            if(isBadVersion(index))
            {
                sol = index;
                rightSide=index-1;
            }
            else
            {
                leftSide=index+1;
            }
        } 
        return sol;
    }
};