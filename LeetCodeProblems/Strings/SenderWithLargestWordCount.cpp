#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> messageBySender;
        string senderSelected;
        int maxNumber = INT_MIN;
        for(int i=0;i<messages.size();i++)
        {
            messageBySender[senders[i]]+=countWords(messages[i]);
        }
        for(auto it=messageBySender.rbegin();it!=messageBySender.rend();it++)
        {
            if(maxNumber<it->second)
            {
                senderSelected=it->first;
                maxNumber = it->second;
            }
        }
        return senderSelected;
    }
private:
    int countWords(string& s)
    {
        int count =1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ') count++;
        }
        return count;
    }
};