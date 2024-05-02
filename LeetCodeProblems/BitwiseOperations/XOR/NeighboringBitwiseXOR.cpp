using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int s = 0;
        int c = 0;
        for(int i=0;i<derived.size();i++) c = (derived[i])? !c : c;
        if(s==c) return true;
        s = 1;
        c = 1;
        for(int i=0;i<derived.size();i++) c = (derived[i])? !c : c;
        if(s==c) return true;
        return false;
    }
};