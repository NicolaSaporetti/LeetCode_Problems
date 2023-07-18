#include <set>
using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string> s;
        string num = "";
        bool valid = false;
        for(auto& e : word)
        {
            if(e>='0' && e<='9')
            {
                valid = true;
                num.push_back(e);
            }
            else
            {
                reverse(begin(num),end(num));
                while(num.size()>0 && num.back()=='0') num.pop_back();
                if(valid) s.insert(num);
                valid = false;
                num = "";
            }
        }
        reverse(begin(num),end(num));
        while(num.size()>0 && num.back()=='0') num.pop_back();
        if(valid) s.insert(num);
        return s.size();
    }
};