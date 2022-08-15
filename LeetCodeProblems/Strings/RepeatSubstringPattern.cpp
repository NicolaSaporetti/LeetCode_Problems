#include <iostream>
using namespace std;

class Solution {
public:
    string repeat(string s, int n){
        cout<<s<<endl;
        string k = "";
        for(int i=0; i<n; i++) k+=s;
        return k;
    }
    bool repeatedSubstringPattern(string s) {
		int n = s.size();
        for(int i=n/2; i>=1; i--){
            if(n%i==0){
                if((repeat(s.substr(0, i), n/i)==s))
                    return true;
            }
        }
        return false;
    }
};