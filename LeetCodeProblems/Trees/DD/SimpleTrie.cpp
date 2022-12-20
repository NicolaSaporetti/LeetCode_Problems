class Trie {
    public:
        Trie()
        {
            ch.resize(26);
        }
        vector<Trie*> ch;
        bool endWord;

        void insert(string& s)
        {
            auto t = this;
            int sz = s.size();
            for (int j=0;j<sz;j++) {
                char c = s[j];
                if (!t->ch[c - 'a']) t->ch[c - 'a'] = new Trie();
                t = t->ch[c - 'a'];
            }
            t->endWord = true;
        }
};