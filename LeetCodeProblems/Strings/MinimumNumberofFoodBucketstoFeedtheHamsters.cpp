using namespace std;

class Solution {
public:
   int minimumBuckets(string street) {
       int res=0;
       for(int i=0;i<street.size();i++){
           if(street[i]=='H'){
               if(i-1>=0 and street[i-1]=='A')continue;
               if(i+1<street.size() and street[i+1]=='.'){
                   res++;
                   street[i+1]='A';
                   continue;
               }
               if(i-1>=0 and street[i-1]=='.'){
                   res++;
                   continue;
               }
               return -1;
           }
       }
       return res;
   }
};