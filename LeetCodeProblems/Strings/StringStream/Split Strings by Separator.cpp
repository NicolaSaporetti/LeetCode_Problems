#include <vector>
using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        for(auto& e : words)
        {
            stringstream stream(e);
            string w;
            while (getline(stream, w, separator))
            {
                if(w!="") res.push_back(w);
            }
        }
        return res;
    }
};