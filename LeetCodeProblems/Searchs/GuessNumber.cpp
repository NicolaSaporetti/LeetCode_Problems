#include <vector>
using namespace std;

class Solution {
public:
    int guessNumber(int n) {
        long long index = 0;
        long long leftSide = 1;
        long long rightSide = n;
        do
        {
            index=(leftSide+rightSide)/2;
            int res = guess(index);
            if(!res) break;
            else if(res==1) leftSide=index+1;
            else rightSide=index-1;
        } while (leftSide<=rightSide);
        return index;
    }
};