#include <vector>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> v(words.size()+1,0);
        vector<int> res;
        for(int i=0;i<words.size();i++)
        {
            v[i+1]=countVowel(words[i])+v[i];
        }
        for(int i=0;i<queries.size();i++) res.push_back(v[queries[i][1]+1]-v[queries[i][0]]);
        return res;                                                                      
    }
private:
    int countVowel(string& s)
    {
        char el = s.front();
        char elb = s.back();
        return ((el=='a' || el=='e' || el=='i' || el=='o' || el=='u') && (elb=='a' || elb=='e' || elb=='i' || elb=='o' || elb=='u'));
    }
};