using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string s;
        int res = 0;
        for(int i=1;;i++)
        {
            s+=word;
            if(sequence.find(s)==std::string::npos)
            {
                res = i-1;
                break;
            }
        }
        return res;
    }
};