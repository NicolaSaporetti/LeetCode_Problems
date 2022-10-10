#include <set>
using namespace std;

class LUPrefix {
public:
    LUPrefix(int n) {
        for(int i=1;i<=n+1;i++) a.insert(i);
    }
    
    void upload(int video) {
        a.erase(video);
    }
    
    int longest() {
        return *a.begin()-1;
    }
    set<int> a;
};