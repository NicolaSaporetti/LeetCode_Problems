#include <unordered_map>
#include <vector>
using namespace std;

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++)
        {
            m[cuisines[i]][ratings[i]].insert(foods[i]);
            b[foods[i]]=cuisines[i];
            p[cuisines[i]][foods[i]]=ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = b[food];
        int rat = p[cuisine][food];
        m[cuisine][rat].erase(food);
        if(m[cuisine][rat].empty()) m[cuisine].erase(rat);

        m[cuisine][newRating].insert(food);
        p[cuisine][food]=newRating;
    }
    
    string highestRated(string cuisine) {
        return *(m[cuisine].rbegin()->second.begin());
    }

    map<string,map<int,set<string>>> m;
    map<string,string> b;
    map<string,map<string,int>> p;
};