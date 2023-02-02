using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int sz1 = str1.size();
        int sz2 = str2.size();
        for(int i=min(sz1,sz2);i>=1;i--)
        {
            if(sz1%i!=0 || sz2%i!=0) continue;
            string tempSubstring = str1.substr(0,i);
            if(isConcatenated(str1,i,tempSubstring) && isConcatenated(str2,i,tempSubstring)) return tempSubstring;
        }
        return "";
    }
private:
    bool isConcatenated(string& str, int baseStringSize, string& substring)
    {
        int repetition = str.size()/baseStringSize;
        for(int i=0;i<repetition;i++)
        {
            for(int j=0;j<baseStringSize;j++)
            {
                if(str[i*baseStringSize+j]!=substring[j]) return false;
            }
        }
        return true;
    }
};