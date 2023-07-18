#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        live = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        expire(currentTime);
        int newT = currentTime+live;
        tokens[tokenId] = newT;
        expiration[newT].insert(tokenId);
    }
    
    void renew(string tokenId, int currentTime) {
        expire(currentTime);
        if(tokens.count(tokenId)>0)
        {
            int old = tokens[tokenId];
            int newT = currentTime+live;
            tokens[tokenId] = newT;
            expiration[old].erase(tokenId);
            expiration[newT].insert(tokenId);
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        expire(currentTime);
        return tokens.size();
    }
    
private:
    void expire(int currentTime)
    {
        auto it = expiration.begin();
        while(it!=expiration.end() && it->first<=currentTime)
        {
            for(auto& e : it->second) tokens.erase(e);
            expiration.erase(it++);
        }
    }
    
    map<string,int> tokens;
    map<int,unordered_set<string>> expiration;
    int live;
};