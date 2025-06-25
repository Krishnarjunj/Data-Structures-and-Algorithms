class Solution {
public:
    void bfs(int r, int c, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c] = '0'; // Mark visited

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = row + drow[i];
                int nc = col + dcol[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1') {
                    q.push({nr, nc});
                    grid[nr][nc] = '0'; // Mark as visited
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    bfs(i, j, grid); // visit and mark the whole island
                }
            }
        }
        return count;
    }
};
