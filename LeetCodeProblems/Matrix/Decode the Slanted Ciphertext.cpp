#include <vector>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string res;
        int sz = encodedText.size();
        int cz = sz/rows;
        for(int i=0;i<cz;i++)
        {
            for(int j=i;j<sz;j+=(cz+1)) res.push_back(encodedText[j]);
        }
        while(res.back()==' ') res.pop_back();
        return res;
    }
};