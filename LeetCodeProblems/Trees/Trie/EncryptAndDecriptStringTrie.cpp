#include <vector>
#include <unordered_map>
#include "Trie.cpp"
using namespace std;

class Encrypter {
    Trie* t;
    unordered_map<char, string> K_V;
    unordered_map<string, vector<char>> V_Ks;
public:
    Encrypter(vector<char>& K, vector<string>& V, vector<string>& D) : t(new Trie()) { 
        for(int i = 0; i < size(K); i++)
        {
            K_V[K[i]] = V[i], 
            V_Ks[V[i]].push_back(K[i]);
        }
        for(auto& d : D) t -> insert(d);
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
        return dfs(W, t, 0);
    }
    
    int dfs(string& W, Trie* T, int i) {
        if(i == size(W)) return T->endWord;
        int ans = 0;
        string s = W.substr(i, 2);
        for(auto c : V_Ks[s]) 
            if(T -> ch[c-'a']) 
                ans += dfs(W, T -> ch[c-'a'], i+2);
        return ans;
    }
};