#include <map>
#include <set>
#include <vector>
using namespace std;

class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        shops.resize(n);
        for(auto& e : entries)
        {
            int shop = e[0];
            int movie = e[1];
            int price = e[2];
            shops[shop][movie] = price;
            moviePrice[movie][price].insert(shop);
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        int used = 0;
        for(auto it = moviePrice[movie].begin(); it!=moviePrice[movie].end();it++)
        {
            for(auto& e : it->second)
            {
                res.push_back(e);
                used++;
                if(used==5) return res;
            }
        }
        return res;        
    }
    
    void rent(int shop, int movie) {
        int price = shops[shop][movie];
        moviePrice[movie][price].erase(shop);
        cost[price][shop].insert(movie);
    }
    
    void drop(int shop, int movie) {
        int price = shops[shop][movie];
        moviePrice[movie][price].insert(shop);
        cost[price][shop].erase(movie);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int used = 0;
        for(auto& [c,val] : cost)
        {
            for(auto& [shop,val2] : val)
            {
                for(auto& movie : val2)
                {
                    res.push_back({shop,movie});
                    used++;
                    if(used==5) return res;
                }
            }
        }
        return res;
    }
    
    vector<map<int,int>> shops;
    map<int,map<int,set<int>>> moviePrice;
    map<int,map<int,set<int>>> cost;
};