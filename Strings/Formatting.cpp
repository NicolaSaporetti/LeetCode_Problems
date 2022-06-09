#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> result;
    string s;
    int maxWidth;
    int currentWord;
    int totalWordsByRow;
    int totalRowSizeLeft;
    
    void fillWord(vector<string>& words, int& count, int wordNumber)
    {
        for(int j=0;j<words[wordNumber].size();j++)
        {
            s[count++] = words[wordNumber][j];
        }
    }
    
    void fillRow(vector<string>& words)
    {
        int count = 0;
        int startingWord = currentWord-totalWordsByRow;
        for(int i=0;i<totalWordsByRow-1;i++)
        {
            fillWord(words, count, startingWord+i);
            int spaces = totalRowSizeLeft/(totalWordsByRow-1);
            for(int j=0;j<spaces+1;j++) s[count++] = ' ';
            if(totalRowSizeLeft%(totalWordsByRow-1)!=0)
            {
                s[count++] = ' ';
                totalRowSizeLeft--;
            }
        }
        fillWord(words, count, currentWord-1);
        result.push_back(s);
    }
    
    void fillLastRow(vector<string>& words)
    {
        int count = 0;
        int startingWord = currentWord-totalWordsByRow;
        for(int i=0;i<totalWordsByRow;i++)
        {
            fillWord(words, count, startingWord+i);
            s[count++] = ' ';
        }
        int spaces = maxWidth-count;
        for(int j=0;j<spaces;j++) s[count++] = ' ';
        result.push_back(s);
    }
    
    void fillSingleRow(vector<string>& words)
    {
        int count = 0;
        fillWord(words, count, currentWord-1);
        int spaces = maxWidth-words[currentWord-1].size();
        for(int j=0;j<spaces;j++) s[count++] = ' ';
        result.push_back(s);
    }
    
    void formatLineBasedOnType(vector<string>& words)
    {
        if(totalWordsByRow!=1)
        {
            if(currentWord < words.size()) fillRow(words);
            else fillLastRow(words);
        }
        else fillSingleRow(words);
    }
    
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        this->maxWidth = maxWidth;
        s.resize(maxWidth);
        for(currentWord=0;currentWord<words.size();)
        {
            totalWordsByRow = 0;
            totalRowSizeLeft = maxWidth;
            while(currentWord < words.size() && totalRowSizeLeft>0 && totalRowSizeLeft>=words[currentWord].size())
            {
                totalRowSizeLeft -= (words[currentWord].size() +1);
                totalWordsByRow++;
                currentWord++;
            }
            totalRowSizeLeft++; //Remove space at end
            formatLineBasedOnType(words);
        }
        return result;
    }
};