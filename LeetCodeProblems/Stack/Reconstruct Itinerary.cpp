#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;

        for (auto& ticket : tickets) graph[ticket[0]].push_back(ticket[1]);

        for (auto& [_, dests] : graph) {
            sort(dests.begin(), dests.end(), greater<string>());
        }

        vector<string> stack = {"JFK"};
        vector<string> itinerary;

        while (!stack.empty()) {
            string curr = stack.back();
            if (graph.find(curr) != graph.end() && !graph[curr].empty()) {
                stack.push_back(graph[curr].back());
                graph[curr].pop_back();
            }
            else {
                itinerary.push_back(stack.back());
                stack.pop_back();
            }
        }

        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};