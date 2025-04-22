#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int islands = 0;
        int directions[4][2] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        set<pair<int, int>> visited;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && !visited.count({i, j})) {
                    bfs(grid, visited, directions, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }

    void bfs(vector<vector<char>>& grid, set<pair<int, int>>& visited, int directions[4][2], int i, int j) {
        queue<pair<int, int>> queue;
        visited.insert({i, j});
        queue.push({i, j});

        int rows = grid.size();
        int cols = grid[0].size();

        while (!queue.empty()) {
            pair<int, int> current = queue.front();
            queue.pop();

            int row = current.first;
            int col = current.second;

            for (int d = 0; d < 4; d++) {
                int newRow = row + directions[d][0];
                int newCol = col + directions[d][1];

                if (newRow >= 0 && newRow < rows &&
                    newCol >= 0 && newCol < cols &&
                    !visited.count({newRow, newCol}) &&
                    grid[newRow][newCol] == '1') 
                {
                    visited.insert({newRow, newCol});
                    queue.push({newRow, newCol});
                }
            }
        }
    }
};

int main() {
    Solution solution;

    vector<vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << "Test Case 1: Expected: 1, Got: " << solution.numIslands(grid1) << endl;

    vector<vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << "Test Case 2: Expected: 3, Got: " << solution.numIslands(grid2) << endl;

    vector<vector<char>> grid3 = {
        {'0','0','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << "Test Case 3: Expected: 0, Got: " << solution.numIslands(grid3) << endl;

    vector<vector<char>> grid4 = {
        {'1','0','1','0','1'},
        {'0','1','0','1','0'},
        {'1','0','1','0','1'}
    };
    cout << "Test Case 4: Expected: 8, Got: " << solution.numIslands(grid4) << endl;

    return 0;
}
