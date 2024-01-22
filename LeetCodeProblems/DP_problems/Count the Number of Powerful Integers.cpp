#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> cnt;
    long long count(char l, const string &n, const string &s) {
        long long res = 0, i = 0, sz = n.size() - s.size();
        do
        {
            res += (i == sz) ? n.substr(i) >= s : cnt[n.size() - i - 1] * (min(l, n[i]) - '0');
        }
        while (i < sz && n[i++] < l);
        return res;
    } 
    long long numberOfPowerfulInt(long long start, long long finish, int limit, const string &s) {
        cnt.assign(17,0);
        cnt[s.size()]=1;
        for (int i = s.size()+1; i < 17; ++i) cnt[i] = cnt[i-1] * (limit + 1);
        return count('1' + limit, to_string(finish), s) - count('1' + limit, to_string(start - 1), s);
    }
};