#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int wordsByRow = 0;
        for(int startWord=0;startWord<words.size();startWord+=wordsByRow)
        {
            wordsByRow = 0;
            totalRowSizeLeft = maxWidth;
            while(startWord+wordsByRow < words.size() && totalRowSizeLeft>=(int)words[startWord+wordsByRow].size())
            {
                totalRowSizeLeft -= (words[startWord+wordsByRow].size() +1);
                wordsByRow++;
            }
            totalRowSizeLeft++; //Remove space at end
            formatLineBasedOnType(words,startWord,wordsByRow);
        }
        return result;
    }
    
private:
    void formatLineBasedOnType(vector<string>& words, int startWord, int wordsByRow)
    {
        if(wordsByRow!=1)
        {
            if(startWord+wordsByRow!=words.size()) fillRow(words,startWord,wordsByRow);
            else fillLastRow(words,startWord,wordsByRow);
        }
        else fillRowSingleWord(words[startWord]);
    }  
    
    void fillRow(vector<string>& words, int startWord, int wordsByRow)
    {
        string s;
        int added_spaces = totalRowSizeLeft/(wordsByRow-1);
        totalRowSizeLeft-=(added_spaces*(wordsByRow-1));
        for(int i=0;i<wordsByRow-1;i++)
        {
            s+=words[startWord+i];
            for(int j=0;j<1+added_spaces;j++) s+=' ';
            if(totalRowSizeLeft>0)
            {
                s+=' ';
                totalRowSizeLeft--;
            }
        }
        s+=words[startWord+wordsByRow-1];
        result.push_back(s);
    }
    
    void fillLastRow(vector<string>& words, int startWord, int wordsByRow)
    {
        string s;
        for(int i=0;i<wordsByRow-1;i++) s+=words[startWord+i]+' ';
        s+=words[startWord+wordsByRow-1];
        for(int j=0;j<totalRowSizeLeft;j++) s+=' ';
        result.push_back(s);
    }
    
    void fillRowSingleWord(string& word)
    {
        string s = word;
        while(totalRowSizeLeft>0)
        {
            s+=' ';
            totalRowSizeLeft--;
        }
        result.push_back(s);
    }
    
    vector<string> result;
    int totalRowSizeLeft;
};