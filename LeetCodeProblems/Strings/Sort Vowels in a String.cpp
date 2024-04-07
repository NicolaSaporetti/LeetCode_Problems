#include <vector>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        vector<char> v;
        int pos = 0;
        for(auto& e : s) if(e=='a' || e=='A' || e=='e' || e=='E' || e=='I' || e=='i' || e=='O' || e=='o' || e=='u' || e=='U') v.push_back(e);
        sort(begin(v),end(v));
        pos = 0;
        for(auto& e : s) if(e=='a' || e=='A' || e=='e' || e=='E' || e=='I' || e=='i' || e=='O' || e=='o' || e=='u' || e=='U') e = v[pos++];
        return s;
    }
};