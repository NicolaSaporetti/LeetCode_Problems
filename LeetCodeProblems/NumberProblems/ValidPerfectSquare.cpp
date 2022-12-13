using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i=0;
        for(i=1;num>i*i;i++);
        return (i*i==num)? true : false;
    }
};