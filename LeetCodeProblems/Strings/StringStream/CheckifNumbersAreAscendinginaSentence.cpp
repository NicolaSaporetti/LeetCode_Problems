#include <vector>
using namespace std;

class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> seq;
        stringstream stream(s);
	    string w;
	    while (getline(stream, w, ' '))
        {
            if(w[0]>='0' && w[0]<='9') seq.push_back(stoi(w));
        }
        for(int i=0;i<seq.size()-1;i++) if(seq[i]>=seq[i+1]) return false;
        return true;
    }
};