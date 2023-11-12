#include <vector>
using namespace std;

class OrderedStream {
public:
    OrderedStream(int n) {
        v.resize(n);
        used.assign(n,false);
        prev = 0;
    }
    
    vector<string> insert(int idKey, string value) {
        v[idKey-1]=value;
        used[idKey-1]=true;
        if(prev>idKey-1) return {};
        for(int i=prev;i<=idKey-1;i++) if(!used[i]) return {};
        vector<string> v1;
        for(;prev<used.size() && used[prev];prev++) v1.push_back(v[prev]);
        return v1;
    }
    
    vector<string> v;
    vector<bool> used;
    int prev;
};