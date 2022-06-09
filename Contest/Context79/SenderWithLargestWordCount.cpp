#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    map<string, int> myMap;
    int countWord(string s)
    {
        int count = 0;
        for(int i=0;i<s.size();i++)
        {
            count++;
            while(i<s.size() && s[i]!=' ')
            {
                i++;
            }
        }
        return count;
    }
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int max = -1;
        for(int i=0;i<messages.size();i++)
        {
            int words = countWord(messages[i]);
            auto pair = myMap.insert(std::pair<string,int>(senders[i], words));
            if(pair.second == false)
            {
                words+=pair.first->second;
                myMap.erase(pair.first);
                myMap.insert(std::pair<string,int>(senders[i], words));
            }
        }
        auto it2 = myMap.begin();
        for(auto it=myMap.begin();it!=myMap.end();it++)
        {
            if(it->second>=max)
            {
                max = it->second;
                it2 = it;
            }
        }
        return it2->first;
    }
};