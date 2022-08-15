#include <iostream>
using namespace std;

class Solution {
    private:
    bool isStringCorrect;
    int verifyNumber(string& s)
    {
        int pos = 0;
        while(s.size()>pos && s[pos]>=48 && s[pos]<=57) pos++;
        return pos;
    }
    void check_string_not_empty(string& s)
    {
        if(s.size()!=0)
        {
            isStringCorrect = false;
            return;
        }
    }
    void check_exp_number(string& s)
    {
        int pos = verifyNumber(s);
        if(pos>0)
        {
            isStringCorrect = true;
            s = s.substr(pos);
            check_string_not_empty(s);
        }
        return;
    }
    void check_exp_sign(string& s)
    {
        if(s.size()==0) return;
        if(s[0]=='+' || s[0]=='-')
        {
            s = s.substr(1);
            check_exp_number(s);
        }
        else check_exp_number(s);
    }
    void check_exponent(string& s)
    {
        if(s.size()==0) return;
        if(s[0]=='e' || s[0]=='E')
        {
            isStringCorrect = false;
            s = s.substr(1);
            check_exp_sign(s);
        }
        else check_string_not_empty(s);
    }
    void check_number_after_comma_with_number(string& s)
    {
        int pos = verifyNumber(s);
        s = s.substr(pos);
        check_exponent(s);
    }
    void check_number_after_comma(string& s)
    {
        int pos = verifyNumber(s);
        if(pos>0)
        {
            isStringCorrect = true;
            s = s.substr(pos);
            check_exponent(s);
        }
        else return;
    }
    void check_comma_after_number(string& s)
    {
        if(s.size()==0) return;
        if(s[0]=='.') 
        {
            s = s.substr(1);
            check_number_after_comma_with_number(s);
        }
        else check_exponent(s);
    }
    void check_number_before_comma(string& s)
    {
        int pos = verifyNumber(s);
        if(pos>0)
        {
            isStringCorrect = true;
            s = s.substr(pos);
            check_comma_after_number(s);
        }
        else return;
    }
    void check_comma(string& s)
    {
        if(s.size()==0) return;
        if(s[0]=='.')
        {
            s = s.substr(1);
            check_number_after_comma(s);
        }
        else check_number_before_comma(s);
    }
    void check_first_sign(string& s)
    {
        if(s.size()==0) return;
        if(s[0]=='+' || s[0]=='-')
        {
            s=s.substr(1);
            check_comma(s);
        }
        else check_comma(s);
    }
public:
    bool isNumber(string s) {
        isStringCorrect = false;
        check_first_sign(s);
        return isStringCorrect;
    }
};