#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        words = wordList.size();
        wordSize = wordList[0].size();
        int end_word_pos = getWordPos(endWord, wordList);
        visited.resize(words,false);
        if(end_word_pos!=words)
        {
            addStartingWordIfNotInVector(beginWord,wordList);
            int start_word_pos = getWordPos(beginWord,wordList);
            fillWordsGraph(wordList);
            visited[end_word_pos] = true;
            successor.resize(words);
            addAllElementDistanceOne(end_word_pos,wordList);
            computeMinDistance(start_word_pos,wordList);
            vector<int> temp(minDistance+1);
            computeResult(start_word_pos,end_word_pos,wordList,temp,0);
        }
        return result;
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
    
    void addStartingWordIfNotInVector(string& word, vector<string>& wordList)
    {
        int pos = getWordPos(word, wordList);
        if(pos==words)
        {
            wordList.push_back(word);
            words++;
        }
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
    
    void computeMinDistance(int end_pos, vector<string>& wordList)
    {
        minDistance = 0;
        while(!wordsToEvaluate.empty())
        {
            minDistance++;
            set<int> temp;
            for(auto it = wordsToEvaluate.begin();it!=wordsToEvaluate.end();it++)
            {
                temp.insert(*it);
                visited[*it] = true;
            }
            wordsToEvaluate.clear();
            for(auto it = temp.begin();it!=temp.end();it++)
            {
                if(*it == end_pos) return;
                else
                {
                    addAllElementDistanceOne(*it, wordList);
                }
            }
        }
        return;
    }
    
    void addAllElementDistanceOne(int source, vector<string>& wordList)
    {
        for(auto i=wordsGraph[source].begin();i!=wordsGraph[source].end();i++)
        {
            if(!visited[*i])
            {
                wordsToEvaluate.insert(*i);
                successor[*i].push_back(source);
            }
            wordsGraph[*i].erase(source);
        }
        wordsGraph.erase(source);
    }
    
    void computeResult(int current, int end, vector<string>& wordList, vector<int>& path, int pos)
    {
        path[pos]=current;
        if(current==end)
        {
            vector<string> t(pos+1);
            for(int i=0;i<=pos;i++) t[i]=wordList[path[i]];
            result.push_back(t);
        }
        else if(minDistance>pos)
        {
            for(int i=0;i<successor[current].size();i++)
            {
                computeResult(successor[current][i],end,wordList,path,pos+1);
            }
        }
    }
    
    set<int> wordsToEvaluate;
    map<int,set<int>> wordsGraph;
    vector<bool> visited;
    int words;
    int wordSize;
    vector<vector<string>> result;
    vector<vector<int>> successor;
    int minDistance;
};