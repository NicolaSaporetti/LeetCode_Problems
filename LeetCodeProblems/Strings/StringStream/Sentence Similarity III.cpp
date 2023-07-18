#include <vector>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> v1;
        vector<string> v2;
        stringstream ss (sentence1);
        string word;
        while (ss >> word) v1.push_back(word);
        stringstream ss2(sentence2);
        while (ss2 >> word) v2.push_back(word);
        while(!v1.empty() && !v2.empty() && v1.back()==v2.back())
        {
            v1.pop_back();
            v2.pop_back();
        }
        int i=0;
        while(i<v1.size() && i<v2.size() && v1[i]==v2[i]) i++;
        return i>=v1.size() || i>=v2.size();
    }
};