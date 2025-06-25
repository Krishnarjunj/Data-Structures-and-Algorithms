class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0 ; i < n ; i ++){
            if(grid[i][0]==1){
                grid[i][0] = -1;
                q.push({i,0});
            }
            if(grid[i][m-1]==1){
                grid[i][m-1]=-1;
                q.push({i,m-1});
            }
        }
        for(int i = 0 ; i < m ; i++){
            if(grid[0][i] == 1){
                grid[0][i] = -1;
                q.push({0,i});
            }
            if(grid[n-1][i]==1){
                grid[n-1][i] = -1;
                q.push({n-1,i});
            }
        }
        int drow[4] = {1,0,-1,0};
        int dcol[4] = {0,1,0,-1};
        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();
            for(int i= 0 ; i < 4 ; i++){
                int nr = row + drow[i];
                int nc = col + dcol[i];
                if(nr>=0 && nr < n && nc>=0 && nc < m && grid[nr][nc]==1){
                    grid[nr][nc] = -1;
                    q.push({nr,nc});
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};
