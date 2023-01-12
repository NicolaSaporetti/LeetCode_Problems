#include <map>
using namespace std;

class MyCalendarThree {
public:
    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        mp[start]++, mp[end]--;
        int ans = 0
        int curr = 0;
        
        for(auto &i : mp)
        {
            curr += i.second;
            ans = max(ans, curr);
        }
        
        return ans;
    }
private:
    map<int,int> mp;
};