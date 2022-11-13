using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss (s);
        int val = 0;
        string word;
        while (ss >> word) val = word.size();
        return val;
    }
};