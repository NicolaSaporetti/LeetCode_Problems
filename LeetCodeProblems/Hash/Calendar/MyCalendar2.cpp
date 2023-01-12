#include <map>
using namespace std;

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++, mp[end]--;
        bool ans = true;
        int curr = 0;
        
        for(auto &i : mp)
        {
            curr += i.second;
            if(curr>2)
            {
                mp[start]--, mp[end]++;
                ans = false;
                break;
            }
        }
        
        return ans;
    }
private:
    map<int,int> mp;
};