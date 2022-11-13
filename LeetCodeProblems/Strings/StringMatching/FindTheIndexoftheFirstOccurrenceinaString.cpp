using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i+needle.size()<=haystack.size();i++) if(needle==haystack.substr(i,needle.size())) return i;
        return -1;
    }
};