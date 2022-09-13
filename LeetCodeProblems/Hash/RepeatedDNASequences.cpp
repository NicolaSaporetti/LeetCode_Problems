#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> myM;
        vector<string> solutions;
        for(int i=9;i<s.size();i++)
        {
            string a = s.substr(i-9,10);
            auto it=myM.find(a);
            if(it!=myM.end())
            {
                it->second++;
                if(it->second ==2) solutions.push_back(a);
            }
            else
            {
                myM.insert(make_pair(a,1));
            }
        }
        return solutions;
    }
};