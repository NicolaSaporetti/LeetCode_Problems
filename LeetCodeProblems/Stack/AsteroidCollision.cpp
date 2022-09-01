#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for(int i=0;i<asteroids.size();i++)
        {
            if(asteroids[i]>0)
            {
                s.push_back(asteroids[i]);
            }
            else
            {
                while(!s.empty() && s[s.size()-1]>0 && s[s.size()-1]<abs(asteroids[i])) s.pop_back();
                if(!s.empty() && s[s.size()-1]>0 && s[s.size()-1]==abs(asteroids[i])) s.pop_back();
                else if(s.empty() || s[s.size()-1]<0) s.push_back(asteroids[i]);
            }
        }
        return s;
    }
};