class Trie {
public:
    Trie()
    {
        ch.resize(2);
    }

    void insert(int n)
    {
        Trie* t = this;
        for(int i=30;i>=0;i--)
        {
            bool node = n&(1<<i);
            if(t->ch[node]==nullptr) t->ch[node] = new Trie();
            t = t->ch[node];
        }
    }

    int search(int n)
    {
        Trie* t = this;
        int res = 0;
        if(t->ch[0]==nullptr && t->ch[1]==nullptr) return -1;
        for(int i=30;i>=0;i--)
        {
            res*=2;
            bool node = !(n&(1<<i));
            if(t->ch[node]==nullptr) t=t->ch[!node];
            else
            {
                t = t->ch[node];
                res++;
            }
        }
        return res;
    }
    
    vector<Trie*> ch;
};