class Trie {
public:
    Trie()
    {
        ch.resize(26);
        endWord = false;
    }

    void insert(string& word)
    {
        Trie* t = this;
        for(auto& c : word)
        {
            if(t->ch[c-'a']==nullptr) t->ch[c-'a'] = new Trie();
            t = t->ch[c-'a'];
        }
        t->endWord = true;
    }
    
    bool endWord;
    vector<Trie*> ch;
};