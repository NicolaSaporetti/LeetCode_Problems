#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        string result = "0A0B";
        int bulls = 0;
        int cows = 0;
        vector<vector<int>> numberIncorrectPosition(10,vector<int>(2,0));
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i]) bulls++;
            else
            {
                numberIncorrectPosition[secret[i]-'0'][0]++;
                numberIncorrectPosition[guess[i]-'0'][1]++;
            }
        }
        for(int i=0;i<10;i++)
        {
            cows+=min(numberIncorrectPosition[i][0],numberIncorrectPosition[i][1]);
        }
        return to_string(bulls)+'A'+to_string(cows)+'B';
    }
};