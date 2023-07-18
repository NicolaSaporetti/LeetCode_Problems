using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss (s);
        string res;
        string word;
        while (ss >> word)
        {
            res+=word;
            res+=' ';
            k--;
            if(k==0) break;
        }
        res.pop_back();
        return res;
    }
};