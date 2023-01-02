using namespace std;

class Solution
 {
public:
    bool detectCapitalUse(string word) {
        int sz = word.size();
        int tot =0;
        int pos = 0;
        for(int i=0;i<sz;i++)
            if(word[i]>='A' && word[i]<='Z')
            {
                tot++;
                pos = i;
            }
        if(tot==sz || tot==0 || (tot==1 && pos ==0)) return true;
        else return false;
    }
};