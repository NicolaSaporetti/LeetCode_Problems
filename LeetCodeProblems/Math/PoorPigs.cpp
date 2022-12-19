using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int poisonTime, int totalTime) {
        int y= totalTime/poisonTime+1;
        int z = y;
        int count =1;
        if(buckets==1) return 0;
        while (y<buckets)
        {
            y*=z;
            count++;
        }
        return count;
    }
};