using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int max = 0;
        vector<int> letters(256,0);
        for(int i=0;i<s.size();i++)
        {
            letters[s[i]]++;
            while(letters[s[i]]>1) letters[s[start++]]--;
            if(i-start+1>max) max = i-start+1;
        }
        return max;
    }
};