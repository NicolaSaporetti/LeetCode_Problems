#include <set>
using namespace std;

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        for(int i=1;i<1001;i++)
        {
            s.insert(i);
        }
    }
    
    int popSmallest() {
        int e = *s.begin();
        s.erase(e);
        return e;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
private:
    set<int> s;
};