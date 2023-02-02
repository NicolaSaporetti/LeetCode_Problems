using namespace std;

class Solution {
public:
    int countValidWords(string sentence) {
        stringstream ss (sentence);
        string s;
        int tot = 0;
        while (getline(ss, s, ' ')) {
            if(verifyWord(s)) tot++;
        }
        return tot;
    }
private:
    bool verifyWord(string word)
    {
        int under = 0;
        for(int i=0;i<word.size()-1;i++)
        {
            if(word[i]=='-')
            {
                under++;
                if(i==0 || under>1 || (i==word.size()-2 && (word[i+1]>'z' || word[i+1]<'a'))) return false;
            }
            else if(word[i]>'z' || word[i]<'a') return false;
        }
        if((word.back()>'z' || word.back()<'a') && (word.back()!='.' && word.back()!='!' && word.back()!=',')) return false;
        return true;
    }
};