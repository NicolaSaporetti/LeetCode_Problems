#include <vector>
#include <unordered_map>
using namespace std;

class Encrypter {
    unordered_map<string, int> dic;
    unordered_map<char, string> K_V;
    unordered_map<string, vector<char>> V_Ks;
public:
    Encrypter(vector<char>& K, vector<string>& V, vector<string>& D) {
        for(int i = 0; i < size(K); i++)
        {
            K_V[K[i]] = V[i], 
            V_Ks[V[i]].push_back(K[i]);
        }
        for(auto& d : D) dic[encrypt(d)]++;
    }
    
    string encrypt(string W) {
        string ans = "";
        for(auto c : W)
        {
            if(K_V.find(c) == K_V.end())
            {
                ans.clear();
                break;
            }
            else ans += K_V[c];
        }
        return ans;
    }
    
    int decrypt(string W) {
        return dic[W];
    }
};