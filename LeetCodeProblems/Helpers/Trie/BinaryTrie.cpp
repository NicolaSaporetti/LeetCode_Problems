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
        BinaryTrie* t = this;
        for(int i=31;i>=0;i--)
        {
            bool bit = (num&(1<<i));
            if(t->ch[bit]==nullptr) return 0;
            else t = t->ch[bit];
        }
        return t->freq;
    }

    int findXor(int num)
    {
        return find(~num);
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