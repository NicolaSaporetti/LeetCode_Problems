#include <vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int p1 = 0;
        int p2 = people.size()-1;
        int r = 0;
        while(p1<=p2)
        {
            if(p1==p2 || people[p1]+people[p2]<=limit) p1++;
            r++;
            p2--;
        }
        return r;
    }
};