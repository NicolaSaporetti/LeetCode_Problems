#include <map>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> two_letters;
        for(int i=0;i<words.size();i++)
        {
            two_letters[words[i]]++;
        }
        bool doubleLetter = false;
        int count = 0;
        for(auto it=two_letters.begin();it!=two_letters.end();it++)
        {
            if(it->first[0]==it->first[1])
            {
                count+=((it->second/2)*4);
                if(it->second%2==1) doubleLetter = true;
            }
            else
            {
                string inverseKey = {it->first[1], it->first[0]};
                if(two_letters.find(inverseKey)!=two_letters.end())
                {
                    count+=(2*min(two_letters[inverseKey],it->second));
                }
            }
        }
        if(doubleLetter) count+=2;
        return count;
    }
};