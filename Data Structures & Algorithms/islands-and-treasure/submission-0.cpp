const int LAND = INT_MAX;
const int WATER = -1;
const int TREASURE = 0;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        /*
        Instead of filling each land cell with nearest treasure, we can start with each treasure cell.
        Do multi-source BFS in order to reach each land cell and update it's distance.
        */

        // Base case: grid is empty
        if (grid.empty() || grid[0].empty()) {
            return;
        }

        int rows = grid.size(), cols = grid[0].size();
        
        // Go through each cell and find if it is a treasure cell.
        queue<pair<int, int>> toVisit;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == TREASURE) {
                    toVisit.push({row, col});
                }
            }
        }

        const int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!toVisit.empty()) {
            auto [row, col] = toVisit.front(); toVisit.pop();

            // Check each direction and see if we can find land cell.
            for (auto const &direction: directions) {
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];

                // Check if next cell is out of bounds.
                if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols) {
                    continue;
                }

                // Check if next cell is not land
                if (grid[nextRow][nextCol] != LAND) {
                    continue;
                }

                // Update the distance and push to visit
                grid[nextRow][nextCol] = grid[row][col] + 1;
                toVisit.push({nextRow, nextCol}); 
            }
        }
    }
};
