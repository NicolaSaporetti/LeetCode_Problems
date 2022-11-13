#include <vector>
using namespace std;

class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        sz=message.size();
        limit-=5;
        if(ceil(double(sz)/limit)<=9) execute(message,limit);
        else
        {
            limit--;
            if(ceil(double(sz+90)/limit<=99)) execute(message,limit);
            else
            {
                limit--;
                if(ceil(double(sz+990)/limit<=999)) execute(message,limit);
                else
                {
                    limit--;
                    if(ceil(double(sz+9990)/limit<=9999)) execute(message,limit);
                    else execute(message,--limit);
                }
            }
        }
        return r;        
    }
    
    void execute(string& mes, int limit)
    {
        int letter=0;
        int k=1;
        while(sz>letter)
        {
            if(limit<=0)
            {
                r.clear();
                return;
            }
            int tot = min(limit,sz-letter);
            r.emplace_back(mes.substr(letter,tot)+'<'+to_string(k));
            letter+=tot;
            if(k==9) limit--;
            else if(k==99) limit--;
            else if(k==999) limit--;
            else if(k==9999) limit--;
            k++;
        }
        for(int i=0;i<r.size();i++) r[i]+='/'+to_string(k-1)+'>';
    }
    
    vector<string> r;
    int sz;
};