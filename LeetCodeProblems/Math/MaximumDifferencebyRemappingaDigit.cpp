using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        int res = num;
        int res1 = num;
        vector<int> v;
        while(num>0)
        {
            v.push_back(num%10);
            num/=10;
        }
        int valMax = 0;
        int valMin = 0;
        int value = -1;
        for(int j = v.size()-1;j>=0;j--) if(v[j]!=9)
        {
            value = v[j];
            break;
        }
        for(int j = v.size()-1;j>=0;j--)
        {
            valMax*=10;
            valMin*=10;
            if(v[j]==v.back()) valMin+=0;
            else valMin+=v[j];
            if(v[j]==value) valMax+=9;
            else valMax+=v[j];
        }
        return valMax-valMin;
    }
};