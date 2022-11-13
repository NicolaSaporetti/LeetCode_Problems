#include <vector>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        vector<int> normal={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> roman ={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int solution = 0;
        int pos = 0;
        for(int i=0;i<roman.size();i++){
            while(pos+roman[i].size()<=s.size() && s.substr(pos,roman[i].size())==roman[i]) {
                solution+=normal[i];
                pos+=roman[i].size();
            }
        }
        return solution;
    }
};