using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num1 <= num2) return -1;  
        for(int k=1;k<=32;k++){
            long diff = num1 - ((long)num2 * k);
            int min_cnt = __builtin_popcountl(diff); 
            if(k >= min_cnt && k <= diff) return k;
        }
        return -1;
    }
};