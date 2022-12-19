#include <vector>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<60;j++)
            {
                int pins = compute(i,j);
                if(pins==turnedOn)
                {
                    writeHour(i,j);
                }
            }
        }
        return res;
    }
    
private:
    void writeHour(int h, int m)
    {
        string t;
        t+=to_string(h);
        t.push_back(':');
        if(m<10)
        {
            t.push_back('0');
            t+=to_string(m);
        }
        else t+=to_string(m);
        res.push_back(t);
    }
    
    int compute(int h, int m)
    {
        int tot = 0;
        while(h>0)
        {
            tot+=h%2;
            h/=2;
        }
        while(m>0)
        {
            tot+=m%2;
            m/=2;
        }
        return tot;
    }
    
    int min;
    int hour;
    vector<string> res;
};