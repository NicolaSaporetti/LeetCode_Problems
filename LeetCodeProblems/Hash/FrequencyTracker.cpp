#include <map>
#include <vector>
using namespace std;

class FrequencyTracker {
public:
    FrequencyTracker() {
        num.assign(1e5+1,0);
    }
    
    void add(int number) {
        int prev_freq = num[number];
        freq[prev_freq].erase(number);
        if(freq[prev_freq].size()==0) freq.erase(prev_freq);
        num[number]++;
        freq[num[number]].insert(number);
    }
    
    void deleteOne(int number) {
        int prev_freq = num[number];
        freq[prev_freq].erase(number);
        if(freq[prev_freq].size()==0) freq.erase(prev_freq);
        if(prev_freq>0)
        {
            num[number]--;
            freq[num[number]].insert(number);
        }
    }
    
    bool hasFrequency(int frequency) {
        return freq.count(frequency)>0;
    }
private:
    vector<int> num;
    map<int,unordered_set<int>> freq;
};