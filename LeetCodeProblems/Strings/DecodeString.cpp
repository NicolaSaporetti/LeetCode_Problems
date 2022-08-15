#include <iostream>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int current_pos = 0;
        string result;
        while(current_pos<s.size())
        {
            if(s[current_pos]>='0' && s[i]<='9') result+=get_int(s,current_pos);
            else result+=getStringToRepeat(s,current_pos);
        }
        return result;
    }
    
    string get_int(string& s, int& current_pos)
    {
        string result;
        int start = current_pos++;
        
        while(s[current_pos]>='0' && s[current_pos]<='9') current_pos++;
        int number = stoi(s.substr(start,current_pos-start));
        current_pos++;
        string stringToRepeat;
        while(s[current_pos]!=']')
        {
            if(s[current_pos]>='0' && s[current_pos]<='9') stringToRepeat+=get_int(s,current_pos);
            else stringToRepeat+=getStringToRepeat(s,current_pos);
        }
        current_pos++;
        for(int j=0;j<number;j++) result+=stringToRepeat;
        return result;
    }
    
    string getStringToRepeat(string& s, int& current_pos)
    {
        string result;
        int start = current_pos++;
        
        while(s[current_pos]>='a' && s[start]<='z') current_pos++;
        result = s.substr(start,current_pos-start);
        
        if(s[current_pos]!=']'&& current_pos<s.size()) result+= get_int(s, current_pos);
        return result;
    }
};