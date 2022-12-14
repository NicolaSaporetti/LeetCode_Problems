#include <priority_queue>
#include <vector>
using namespace std;

class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		const int x_size = heightMap.size(), y_size = heightMap.front().size();
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> min_heap;
		for (int i = 1; i < x_size-1; i++) {
			min_heap.push({heightMap[i][0], {i, 0}});
			min_heap.push({heightMap[i][y_size - 1], {i, y_size - 1}});
		}
		for (int j = 1; j < y_size-1; j++) {
			min_heap.push({heightMap[0][j], {0, j}});
			min_heap.push({heightMap[x_size - 1][j], {x_size - 1, j}});
		}
		vector<vector<bool>> visited(x_size, vector<bool>(heightMap.front().size(), false));
		for (int i = 0; i < x_size; i++) {
			visited[i][0] = true;
			visited[i][y_size - 1] = true;
		}
		for (int j = 0; j < y_size; j++) {
			visited[0][j] = true;
			visited[x_size - 1][j] = true;
		}
		int result = 0;
		const vector<int> dx = {-1, 0, 1, 0};
		const vector<int> dy = {0, -1, 0, 1};
		while (!min_heap.empty()) {
			pair<int, pair<int, int>> min_heap_top = min_heap.top();
			min_heap.pop();
			const int x = min_heap_top.second.first;
			const int y = min_heap_top.second.second;
			for (int i = 0; i < 4; i++) {
				const int x_next = x + dx[i];
				const int y_next = y + dy[i];
				if (x_next >= 0 && x_next < x_size && y_next >= 0 && y_next < y_size && !visited[x_next][y_next]) {
					visited[x_next][y_next] = true;
					if (min_heap_top.first >= heightMap[x_next][y_next])
                    {
						result += min_heap_top.first - heightMap[x_next][y_next];
						min_heap.push({min_heap_top.first, {x_next, y_next}});
					}
                    else min_heap.push({heightMap[x_next][y_next], {x_next, y_next}});
				}
			}
		}
		return result;
	}
};