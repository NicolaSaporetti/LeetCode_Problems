using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto it = find(begin(word),end(word),ch);
        if(it!=end(word)) reverse(begin(word),it+1);
        return word;
    }
};