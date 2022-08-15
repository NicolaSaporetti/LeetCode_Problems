#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef struct
{
    int timestamp;
    string value;
} Pair;

class TimeMap {
private:
    map<string,vector<Pair>> myM;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto it = myM.find(key);
        Pair p = {timestamp,value};
        if(it!=myM.end())
        {
            it->second.push_back(p);
        }
        else
        {
            vector<Pair> temp(1,p);
            myM.insert(make_pair(key,temp));
        }
    }
    
    string get(string key, int timestamp) {
        auto it=myM.find(key);
        if(it==myM.end()) return "";
        else 
        {   
            string result;
            int low = 0;
            int high = it->second.size()-1;
            while(low<=high && high>=0 && low<=it->second.size()-1)
            {
                int mid = low+(high-low)/2;
                if(it->second[mid].timestamp>timestamp)
                {
                     high = mid-1;
                }
                else
                {
                    result = it->second[mid].value;
                    low = mid+1;
                }
            }
            return result;
        }
    }
};