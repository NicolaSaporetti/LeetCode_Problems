#include <vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int start=0;
        int end = people.size()-1;
        int res=0;
        while(start<=end)
        {
            if(people[end]+people[start]<=limit) start++;
            end --;
            res++;
        }
        return res;
    }
};