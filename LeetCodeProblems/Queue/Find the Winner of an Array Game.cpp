#include <queue>
using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>arr.size()) return *max_element(begin(arr),end(arr));
        int num = arr[0];
        queue<int> q;
        for(int i=1;i<arr.size();i++) q.push(arr[i]);
        int win = 0;
        while(!q.empty())
        {
            int el = q.front();
            q.pop();
            if(el>num)
            {
                win=1;
                q.push(num);
                num=el;
            }
            else
            {
                win++;
                q.push(el);
            }
            if(win==k) return num;
        }
        return -1;
    }
};