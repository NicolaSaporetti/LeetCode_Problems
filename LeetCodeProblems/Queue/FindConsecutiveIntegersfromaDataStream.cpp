#include <queue>
using namespace std;

class DataStream {
public:
    DataStream(int value, int k) {
        val = value;
        tot = 0;
        sz = k;
    }
    
    bool consec(int num) {
        q.push(num);
        if(num==val) tot++;
        if(q.size()>sz)
        {
            if(q.front()==val) tot--;
            q.pop();
        }
        if(q.size()==sz && tot==sz) return true;
        else return false;
    }
    
    int val;
    int tot;
    queue<int> q;
    int sz;
};