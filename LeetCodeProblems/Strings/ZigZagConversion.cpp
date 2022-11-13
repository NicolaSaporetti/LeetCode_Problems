using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int sz = s.size();
        string result(sz,0);
        if(numRows == 1) return s;
        else{
            int element = 0;
            for(int i=0; i<numRows;i++)
            {
                for(int j=i; j<sz; j+=2*(numRows-1))
                {
                    result[element++] = s[j];
                    int secondElementPos = j+2*(numRows-i-1);
                    if(secondElementPos<sz && i!=0 && i!=numRows-1) result[element++] = s[secondElementPos];
                }
            }
        }
        return result;
    }
};