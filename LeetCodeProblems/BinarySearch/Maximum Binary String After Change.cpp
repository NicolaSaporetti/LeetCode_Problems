using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        if(all_of(begin(binary),end(binary),[](char e){return e=='1';})) return binary;
        string res;
        int i = 0;
        int t = 0;
        for(;i<binary.size();i++) if(binary[i]=='0') break;
        for(int j=i+1;j<binary.size();j++) if(binary[j]=='1') t++;
        for(int j=0;j<t;j++) res.push_back('1');
        res.push_back('0');
        for(int j=0;j<binary.size()-1-t;j++) res.push_back('1');
        reverse(begin(res),end(res));
        return res;
    }
};