#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        vector<string> conversion = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto& word : words)
        {
            string temp;
            for(auto& c : word) temp+=conversion[c-'a'];
            s.insert(temp);
        }
        return s.size();
    }
};