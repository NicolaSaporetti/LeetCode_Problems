#include <iostream>
#include <vector>
#include <map>
#include <set>
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
            addAllElementDistanceOne(start_word_pos,wordList);
            return computeMinDistance(end_word_pos,wordList);
        }
    }

private:
    int getWordPos(string& word, vector<string>& wordList)
    {
        for(int i=0;i<sz;i++)
        {
            if(word.compare(wordList[i])==0) return i;
        }
        return sz;
    }
    
    void fillWordsGraph(vector<string>& wordList)
    {
        for(int i=0;i<sz;i++)
        {
            for(int j=0;j<wordList[i].size();j++)
            {
                string origin = wordList[i];
                origin[j] = '1';
                wordsGraph[origin].insert(i);
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
                cout<<"Elem: "<<elem<<endl;
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
    
    void addAllElementDistanceOne(int elem, vector<string>& wordList)
    {
        for(int j=0;j<wordList[elem].size();j++)
        {
            string origin = wordList[elem];
            origin[j] = '1';
            wordsGraph[origin].erase(elem);
            for(auto i=wordsGraph[origin].begin();i!=wordsGraph[origin].end();i++)
            {
                if(!visited[*i])
                {
                    wordsToEvaluate.push(*i);
                    visited[*i] = true;
                }
            }
            wordsGraph.erase(origin);
        }
    }
    
    queue<int> wordsToEvaluate;
    vector<bool> visited;
    map<string,set<int>> wordsGraph;
    int sz;
};