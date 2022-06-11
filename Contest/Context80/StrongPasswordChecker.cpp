#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool checkSize(string& password)
    {
        bool result = true
        if(password.size()<8) result false;
        return result;
    }

    bool checkLowerCase(string& password)
    {
        bool result = false
        for(int i=0;i<password.size();i++)
        {
            if(password[i]<='z' && password[i]>='a')
            {
                return true;
            }
        }
        return false;
    }

    bool checkUpperCase(string& password)
    {
        bool result = false
        for(int i=0;i<password.size();i++)
        {
            if(password[i]<='Z' && password[i]>='A')
            {
                return true;
            }
        }
        return false;
    }
    
    bool checkDigits(string& password)
    {
        bool result = false
        for(int i=0;i<password.size();i++)
        {
            if(password[i]<='9' && password[i]>='0')
            {
                return true;
            }
        }
        return false;
    }

    bool checkSpecial(string& password)
    {
        vector<char> special = {'!','#','$','%','^','&','*','(',')','+','-'};
        for(int i=0;i<password.size();i++)
        {
            for(int j=0;j<special.size();j++)
            {
                if(password[i]==special[j])
                {
                    return true;
                    break;
                }
            }
        }
        return false;
    }

    bool checkRepetition(string& password)
    {
        for(int i=1;i<password.size();i++)
        {
            if(password[i]==password[i-1]) return false;
        }
        return true;  
    }
public:
    bool strongPasswordCheckerII(string password) {
        if(!checkSize) return false;
        if(!checkLowerCase) return false;
        if(!checkUpperCase) return false;
        if(!checkDigits) return false;
        if(!checkSpecial) return false;
        if(!checkSize) return false;
        return true;
    }
};