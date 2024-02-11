class BinaryTrie {
public:
    BinaryTrie()
    {
        ch.resize(2);
        freq.assign(2,0);
    }

    void insert(int num)
    {
        BinaryTrie* t = this;
        for(int i=31;i>=0;i--)
        {
            bool bit = num&(1<<i);
            if(t->ch[bit]==nullptr) t->ch[bit] = new BinaryTrie();
            t->freq[bit]++;
            t = t->ch[bit];
        }
    }

    int find(int num)
    {
        int res = 0;
        BinaryTrie* t = this;
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
        BinaryTrie* t = this;
        for(int i=31;i>=0;i--)
        {
            bool bit = num&(1<<i);
            t->freq[bit]--;
            if(t->freq[bit]==0)
            {
                t->ch[bit]=nullptr;
                break;
            }
            t = t->ch[bit];
        }
    }
    
    vector<BinaryTrie*> ch;
    vector<int> freq;
};