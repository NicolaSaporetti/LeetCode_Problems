#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> availableConversions;
        vector<string> conversion = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i=0;i<words.size();i++)
        {
            string temp;
            for(int j=0;j<words[i].size();j++)
            {
                temp+=conversion[words[i][j]-'a'];
            }
            availableConversions.insert(temp);
        }
        return availableConversions.size();
    }
};