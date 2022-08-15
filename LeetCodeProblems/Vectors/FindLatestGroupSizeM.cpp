#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        map<int,int> myM;
        myM[0]=0;
        int numberSize = 0;
        int lastStep = -1;
        for(int i=0;i<arr.size();i++)
        {
            auto it=myM.find(arr[i]+1);
            auto it2=--myM.upper_bound(arr[i]);
            bool isNumberFill = numberSize;
            if(it!=myM.end() && it2->first!=0 && it2->second ==arr[i]-1)
            {
                if(it->second-it->first+1==m) numberSize--;
                if(it2->second-it2->first+1==m) numberSize--;
                if(isNumberFill && !numberSize) lastStep = i;
                it2->second = it->second;
                myM.erase(it);
                if(it2->second-it2->first+1==m) numberSize++;
            }
            else if(it!=myM.end())
            {
                if(it->second-it->first+1==m) numberSize--;
                if(isNumberFill && !numberSize) lastStep = i;
                myM[arr[i]]=it->second;
                if(it->second-it->first+2==m) numberSize++;
                myM.erase(it);
            }
            else if(it2->first!=0 && it2->second ==arr[i]-1)
            {
                if(it2->second-it2->first+1==m) numberSize--;
                if(isNumberFill && !numberSize) lastStep = i;
                it2->second++;
                if(it2->second-it2->first+1==m) numberSize++;
            }
            else
            {
                myM[arr[i]]=arr[i];
                if(m==1) numberSize++;
            }
        }
        if(numberSize>0) lastStep = arr.size();
        return lastStep;
    }
};