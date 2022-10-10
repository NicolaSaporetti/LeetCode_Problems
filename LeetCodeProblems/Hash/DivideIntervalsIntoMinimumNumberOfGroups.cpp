class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,vector<int>> m;
        int res = 0;
        for(int i=0;i<intervals.size();i++)
        {
            m[intervals[i][0]].push_back(intervals[i][1]);
        }
        while(!m.empty())
        {
            res++;
            int val = 0;
            auto it = m.begin();
            do
            {
                it = m.upper_bound(val);
                if(it!=m.end())
                {
                    val = it->second[it->second.size()-1];
                    it->second.pop_back();
                    if(it->second.size()==0) m.erase(it);
                }
            } while(it!=m.end());
        }
        return res;
    }
};