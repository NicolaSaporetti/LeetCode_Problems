#include <queue>
using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>=arr.size()-1) return *max_element(begin(arr),end(arr));
        queue<int> q;
        for(int i=1;i<arr.size();i++) q.push(arr[i]);
        int top = arr[0];
        while(true)
        {
            int t = k;
            while(t>0)
            {
                int e = q.front();
                q.pop();
                if(top>e) t--;
                else
                {
                    swap(e,top);
                    t=k-1;
                }
                q.push(e);
            }
            return top;
        }
        return -1;
    }
};