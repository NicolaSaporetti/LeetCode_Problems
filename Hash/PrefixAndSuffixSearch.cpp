#include <iostream>
#include <vector>
#include <map>
using namespace std;

class WordFilter {
    map<string,vector<string>> index;
    map<string,int> dictionary;
public:
    WordFilter(vector<string>& words) {
        string indexPrefix = "aa";
        for(int i=0;i<words.size();i++)
        {
            indexPrefix[0]=words[i][0];
            indexPrefix[1]=words[i][words[i].size()-1];
            auto it = index.find(indexPrefix);
            if(it!=index.end())
            {
                bool exit = false;
                for(int j=0;j<it->second.size() && !exit;j++)
                {
                    if(it->second[j].compare(words[i])==0)
                    {
                        auto it2 = dictionary.find(words[i]);
                        it2->second = i;
                        exit = true;
                    }
                }
                if(!exit)
                {
                    it->second.push_back(words[i]);
                    dictionary.insert(make_pair(words[i],i));
                }
            }
            else
            {
                vector<string> temp(1,words[i]);
                index.insert(make_pair(indexPrefix,temp));
                dictionary.insert(make_pair(words[i],i));
            }
        }
    }
    
    int f(string prefix, string suffix) {
        int res = -1;
        string indexPrefix;
        indexPrefix.push_back(prefix[0]);
        indexPrefix.push_back(suffix[suffix.size()-1]);
        auto it = index.find(indexPrefix);
        if(it!=index.end())
        {
            for(int i=0;i<it->second.size();i++)
            {
                string word = it->second[i];
                if(word.compare(0,prefix.size(),prefix)==0 && word.compare(word.size()-suffix.size(),suffix.size(),suffix)==0)
                {
                    res = max(res, dictionary.find(it->second[i])->second);
                }
            }
        }
        return res;
    }
};