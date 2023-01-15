#include <vector>
#include <unordered_map>
using namespace std;

class WordFilter {
public:
    WordFilter(vector<string>& words) 
    {
        int n = words.size();
        for(int i=0; i<n; i++)
        {
            string word = words[i]; 
            int wordsize = word.size();
            
            for(int j=1; j<=wordsize; j++)
            {
                string pre = word.substr(0,j);
                
                for(int k=0; k<wordsize; k++)
                {
                    string suff = word.substr(k, wordsize);
                    mp[pre + "|" + suff] = i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) 
    {
        string s = prefix + "|" + suffix;
        return mp[s]-1; //if sequence found in hashmap we return its index
    }
private:
    unordered_map<string, int> mp;
};