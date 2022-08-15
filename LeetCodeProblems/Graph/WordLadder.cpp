#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        sz = wordList.size();
        int end_word_pos = getWordPos(endWord, wordList);
        if(end_word_pos==sz) return 0;
        else
        {
            visited.resize(sz);
            int start_word_pos = getWordPos(beginWord, wordList);
            if(start_word_pos==sz)
            {
                wordList.push_back(beginWord);
                sz++;
            }
            for(int i=0;i<sz;i++) visited[i]=false;
            visited[start_word_pos] = true;
            fillWordsGraph(wordList);
            addAllElementDistanceOne(start_word_pos);
            return computeMinDistance(end_word_pos);
        }
    }

private:
    int getWordPos(string& endWord, vector<string>& wordList)
    {
        for(int i=0;i<sz;i++)
        {
            if(endWord.compare(wordList[i])==0) return i;
        }
        return sz;
    }
    
    void fillWordsGraph(vector<string>& wordList)
    {
        wordsGraph.resize(sz);
        for(int i=0;i<sz;i++)
        {
            for(int j=0;j<sz;j++)
            {
                if(computeDistance(wordList[i],wordList[j])==1) wordsGraph[i].push_back(j);
            }
        }
    }
    
    int computeMinDistance(int end_pos)
    {
        int distance = 1;
        while(!wordsToEvaluate.empty())
        {
            distance ++;
            int num = wordsToEvaluate.size();
            for(int i=0;i<num;i++)
            {
                int elem = wordsToEvaluate.front();
                wordsToEvaluate.pop();
                if(elem ==end_pos) return distance;
                else
                {
                    addAllElementDistanceOne(elem);
                }
            }
        }
        return 0;
    }
    
    void addAllElementDistanceOne(int elem)
    {
        for(int i=0;i<wordsGraph[elem].size();i++)
        {
            if(!visited[wordsGraph[elem][i]])
            {
                wordsToEvaluate.push(wordsGraph[elem][i]);
                visited[wordsGraph[elem][i]] = true;
            }
        }
    }
    
    int computeDistance(string& origin, string& dest)
    {
        int res = 0;
        for(int i=0;i<origin.size();i++)
        {
            if(origin[i]!=dest[i]) res++;
        }
        return res;
    }
    
    queue<int> wordsToEvaluate;
    vector<bool> visited;
    vector<vector<int>> wordsGraph;
    int sz;
};