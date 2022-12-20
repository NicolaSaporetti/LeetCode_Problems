#include <vector>
using namespace std;

class Trie {
public:
    Trie()
    {
        ch.resize(26);
    }
    vector<Trie*> ch;
    vector<pair<int,int>> Palindrome;

    void insert(string& s,int word)
    {
        auto t = this;
        int sz = s.size();
        for (int i=sz-1;i>=0;i--) {
            if(isPalindrome(s,0,i))
            {
                t->Palindrome.push_back({word,0});
            }
            int idx = s[i]-'a';
            if (!t->ch[idx]) t->ch[idx] = new Trie();
            t = t->ch[idx];
        }
        t->Palindrome.push_back({word,1});
    }

    void search(string& s, int word, vector<vector<int>>& res)
    {
        auto t = this;
        int sz = s.size();
        for(int i=0;i<sz;i++)
        {
            if(isPalindrome(s,i,sz-1))
            {
                for(int i=0;i<t->Palindrome.size();i++) if(t->Palindrome[i].second==1) res.push_back({word,t->Palindrome[i].first});
            }
            int idx = s[i]-'a';
            if (!t->ch[idx]) return;
            else t = t->ch[idx];
        }
        for(int i=0;i<t->Palindrome.size();i++) if(t->Palindrome[i].first!=word) res.push_back({word,t->Palindrome[i].first});
    }

    bool isPalindrome(string& s,int l, int r)
    {
        int sf=(r-l+1)/2;
        for(int j=0;j<sf;j++) if(s[l+j]!=s[r-j]) return false;
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& A) {
        vector<vector<int>> res;
        Trie trie;
        for(int i=0;i<A.size();i++) trie.insert(A[i],i);
        for(int i=0;i<A.size();i++) trie.search(A[i],i,res);
        return res;
    }
};