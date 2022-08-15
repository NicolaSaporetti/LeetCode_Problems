#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
       string s2;
       int n=s.size();
       for(int i=1;i<=s.size();i++){
           s2.push_back(s[n-i]);
       }      
       vector<vector<int>>v(n+1,vector<int>(n+1));
       for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[n-i]==s2[n-j])
                    v[i][j]=1+v[i-1][j-1];
                else{
                    int a=v[i-1][j];
                    int b=v[i][j-1];
                    int c=v[i-1][j-1];
                    v[i][j]=max(a,max(b,c));
                }
            }            
        }
        return v[n][n];
    }
};