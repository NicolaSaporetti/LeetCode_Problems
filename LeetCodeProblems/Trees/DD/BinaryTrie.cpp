class Trie {
public:
    Trie()
    {
        ch.resize(2);
        num.assign(2,0);
    }

    void insert(int num)
    {
        Trie* t = this;
        for(int i=31;i>=0;i--)
        {
            bool bit = num&(1<<i);
            if(t->ch[bit]==nullptr) t->ch[bit] = new Trie();
            t->num[bit]++;
            t = t->ch[bit];
        }
    }

    int find(int num)
    {
        int res = 0;
        Trie* t = this;
        for(int i=31;i>=0;i--)
        {
            bool bit = !(num&(1<<i));
            if(t->ch[bit]==nullptr)
            {
                t=t->ch[!bit];
                if(bit==0) res|=(1<<i);
            }
            else
            {
                t = t->ch[bit];
                if(bit==1) res|=(1<<i);
            }
        }
        return res;
    }
    void erase(int num)
    {
        Trie* t = this;
        for(int i=31;i>=0;i--)
        {
            bool bit = num&(1<<i);
            t->num[bit]--;
            if(t->num[bit]==0)
            {
                t->ch[bit]=nullptr;
                break;
            }
            t = t->ch[bit];
        }
    }
    
    vector<Trie*> ch;
    vector<int> num;
};