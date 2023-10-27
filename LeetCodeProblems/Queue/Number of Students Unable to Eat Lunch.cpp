#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int sz = students.size();
        queue<int> q;
        for(auto& e : students) q.push(e);
        for(int i=0;i<sz;i++)
        {
            int s = q.size();
            bool sel = false;
            for(int j=0;j<s && !sel;j++)
            {
                if(q.front()==sandwiches[i])
                {
                    q.pop();
                    sel = true;
                }
                else
                {
                    q.push(q.front());
                    q.pop();
                }
            }
            if(!sel) return sz-i;
        }
        return 0;
    }
};