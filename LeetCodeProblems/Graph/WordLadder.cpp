#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        words = wordList.size();
        wordSize = wordList[0].size();
        visited.resize(words,false);
        int end_word_pos = getWordPos(endWord, wordList);
        if(end_word_pos==words) return 0;
        else
        {
            int start_word_pos = getWordPos(beginWord, wordList);
            if(start_word_pos==words)
            {
                wordList.push_back(beginWord);
                words++;
            }
            visited[start_word_pos] = true;
            fillWordsGraph(wordList);
            addAllElementDistanceOne(start_word_pos,wordList);
            return computeMinDistance(end_word_pos,wordList);
        }
    }

private:
    int getWordPos(string& word, vector<string>& wordList)
    {
        for(int i=0;i<words;i++)
        {
            if(word.compare(wordList[i])==0) return i;
        }
        return words;
    }
    
    void fillWordsGraph(vector<string>& wordList)
    {
        map<string,vector<int>> tempWordsGraph;
        for(int i=0;i<words;i++)
        {
            for(int j=0;j<wordSize;j++)
            {
                string origin = wordList[i];
                origin[j] = '*';
                tempWordsGraph[origin].push_back(i);
            }
        }
        
        for(auto it=tempWordsGraph.begin();it!=tempWordsGraph.end();it++)
        {
            for(auto j=0;j<it->second.size();j++)
            {
                for(int k=0;k<it->second.size();k++)
                {
                    if(k==j) continue;
                    wordsGraph[it->second[j]].insert(it->second[k]);
                }
            }
        }
    }
    
    int computeMinDistance(int end_pos, vector<string>& wordList)
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
                    addAllElementDistanceOne(elem, wordList);
                }
            }
        }
        return 0;
    }
    
    void addAllElementDistanceOne(int source, vector<string>& wordList)
    {
        for(auto i=wordsGraph[source].begin();i!=wordsGraph[source].end();i++)
        {
            if(!visited[*i])
            {
                wordsToEvaluate.push(*i);
                visited[*i] = true;
            }
            wordsGraph[*i].erase(source);
        }
        wordsGraph.erase(source);
    }
    
    queue<int> wordsToEvaluate;
    map<int,set<int>> wordsGraph;
    vector<bool> visited;
    int words;
    int wordSize;
};