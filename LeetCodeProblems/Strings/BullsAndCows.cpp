#include <vector>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int sz = secret.size();
        int bulls = 0;
        int cows = 0;
        vector<int> v(10,0);
        for(int i=0;i<sz;i++)
        {
            if(secret[i]==guess[i]) bulls++;
            else v[secret[i]-'0']++;
        }
        for(int i=0;i<sz;i++)
        {
            if(secret[i]!=guess[i] && v[guess[i]-'0']>0)
            {
                cows++;
                v[guess[i]-'0']--;
            }
        }
        return to_string(bulls)+'A'+to_string(cows)+'B';
    }
};