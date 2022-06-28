#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for(int i = 0;i<n;){
            int s = i;          //s is the starting index of subarray
            int c = 0;          //c will keep count of no of negative numbers
            
            while(s<n && nums[s]==0) s++;   //ignore zeroes in starting of the array
            
            int e = s;      //e will be used to traverse the subarray
            int sn = -1;    //index of 1st negative no
            int ln = -1;    //index of last negative no
            
            while(e<n && nums[e]!=0){
                
                if(nums[e]<0){  
                    c++;                //when we encounter a negative no we increament c
                    if(sn==-1) sn = e;  //first negative no.
                    ln = e;
                }
                e++;
            }
			
			//if number of negatives in subarray are even
            if(c%2==0)                                  
                ans = max(ans,e-s);
            else{
                if(sn!=-1) ans = max(ans,e-sn-1);     //remove first negative no
                if(ln!=-1) ans = max(ans,ln-s);       //OR remove last negative no
            }
            
            i = e+1;  //now i will point to the index next to the last element of the current subarray
        }
        return ans;
    }
};