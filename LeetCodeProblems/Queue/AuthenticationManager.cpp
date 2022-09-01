#include <iostream>
#include <queue>
using namespace std;

class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        m[tokenId]=currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        auto it = m.find(tokenId);
        if(it!=m.end() && it->second+timeToLive>currentTime)
        {
            m[tokenId]=currentTime;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        queue<string> toRemove;
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second+timeToLive<=currentTime) toRemove.push(it->first);
        }
        while(!toRemove.empty())
        {
            m.erase(toRemove.front());
            toRemove.pop();
        }
        
        return m.size();
    }
private:
    int timeToLive;
    map<string,int> m;
};