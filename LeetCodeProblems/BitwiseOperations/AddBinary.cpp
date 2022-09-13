using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0;
        int sza = a.size();
        int szb = b.size();
        for(int i=0;i<max(sza, szb) || carry;i++)
        {
            int aI = get_value(a,i);
            int bI = get_value(b,i);
            int value = (aI+bI+carry)%2;
            carry = (aI+bI+carry)/2;
            result.push_back((value)? '1': '0');
        }
        reverse(result.begin(),result.end());
        return result;
    }
    
private:
    int get_value(string& s, int pos)
    {
        if(s.size()<=pos || s[s.size()-pos-1] == '0') return 0;
        else return 1;
    }
};