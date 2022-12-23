#include <vector>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        long long result = -1;
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
            result = convertToLong(digits);
            if(result>INT_MAX) result = -1;
        }
        return result;
    }
private:
    vector<int> convertToVect(int n)
    {
        vector<int> digits;
        while(n>0)
        {
            digits.push_back(n%10);
            n/=10;
        }
        return digits;
    }

    long long convertToLong(vector<int>& digits)
    {
        long long result = 0;
        for(int i=digits.size()-1;i>=0;i--)
        {
            result*=10;
            result+=digits[i];
        }
        return result;
    }
};