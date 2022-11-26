class Trie {
    public:
        array<Trie*,26> ch;
        int visited = 0;
        bool endWord;

        void insert(string& s)
        {
            auto t = this;
            for (char& c: s) {
                if (!t->ch[c - 'a']) t->ch[c - 'a'] = new Trie();
                t->ch[c - 'a']->visited++;
                t = t->ch[c - 'a'];
            }
            t->endWord = true;
        }
};