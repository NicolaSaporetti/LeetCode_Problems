#include <vector>
using namespace std;

class Greater {
public:
    string nextGreaterElement(string n) {
        vector<int> digits=convertToVect(n);
        int i=1;
        while(i<digits.size() && digits[i-1]<=digits[i]) i++;
        if(i<digits.size())
        {
            int val = digits[i];
            swap(digits[i],digits[i-1]);
            for(int j=0;j<i-1;j++)
            {
                if(digits[j]>val && digits[j]<=digits[i]) swap(digits[j],digits[i]);
            }
            sort(digits.begin(),digits.begin()+i, greater<int>());
        }
        return convertToString(digits);
    }
private:
    vector<int> convertToVect(string n)
    {
        vector<int> digits(n.size());
        for(int i=0;i<n.size();i++) digits[n.size()-1-i]=n[i]-'0';
        return digits;
    }

    string convertToString(vector<int>& digits)
    {
        string result(digits.size(),'0');
        for(int i=0;i<digits.size();i++) result[digits.size()-1-i]+=digits[i];
        return result;
    }
};

class Solution {
public:
    int getMinSwaps(string num, int k) {
        Greater conversion;
        string original = num;
        for(int i=0;i<k;i++)num = conversion.nextGreaterElement(num);
        int res = 0;
        for(int i=0;i<num.size();i++)
        {
            if(original[i]==num[i]) continue;
            int dist = find(begin(original)+i,end(original),num[i])-begin(original)-i;
            res+=dist;
            for(int j=0;j<dist;j++) swap(original[i+dist-j],original[i+dist-1-j]);
        }
        return res;
    }
};