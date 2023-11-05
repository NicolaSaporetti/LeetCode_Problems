using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        string res;
        string r;
        for(auto& e : number) if(e>='0' && e<='9') res+=e;
        int sz=res.size();
        int i=0;
        while(sz-i>4)
        {
            r+=res[i++];
            r+=res[i++];
            r+=res[i++];
            r+='-';
        }
        if(sz-i==3)
        {
            r+=res[i++];
            r+=res[i++];
            r+=res[i++];
        }
        else if(sz-i==4)
        {
            r+=res[i++];
            r+=res[i++];
            r+='-';
            r+=res[i++];
            r+=res[i++];
        }
        else
        {
            r+=res[i++];
            r+=res[i++];
        }
        return r;
    }
};