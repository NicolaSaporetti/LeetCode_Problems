using namespace std;

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int sz = s.size();
        int zer = count_if(begin(s),end(s),[](char el){return el=='0';});
        int one = count_if(begin(s),end(s),[](char el){return el=='1';});
        int zerT = count_if(begin(target),end(target),[](char el){return el=='0';});
        int oneT = count_if(begin(target),end(target),[](char el){return el=='1';});
        if((zer!=zerT && zerT == sz) || (zer==sz && oneT-one>0)) return false;
        return true;
    }
};