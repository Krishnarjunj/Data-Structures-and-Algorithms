class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1 && grid[0][0]!=1) return 1;
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0}, 1});

        int drow[4] = {1, 0, -1 , 0};
        int dcol[4] = {0, 1,  0, -1};
        int diax[4] = {1, -1, 1, -1};
        int diay[4] = {1, 1, -1, -1};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            for(int i = 0 ; i < 4; i++){
                int xx = x + drow[i];
                int yy = y + dcol[i];

                if((xx>=0 && xx<n && yy>=0 && yy<n) && grid[xx][yy]!=1 && ( dis + 1 < dist[xx][yy])){
                    dist[xx][yy] = dis + 1;
                    q.push({{xx,yy}, dis + 1});
                }
            }
            for(int i = 0 ; i < 4 ; i ++){
                int xx = x + diax[i];
                int yy = y + diay[i];

                if((xx>=0 && xx<n && yy>=0 && yy<n) && grid[xx][yy]!=1 && ( dis + 1 < dist[xx][yy])){
                    dist[xx][yy] = dis + 1;
                    q.push({{xx,yy}, dis + 1});
                }
            }
        }
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j++){
                if(dist[i][j] == INT_MAX) dist[i][j] = -1;
            }
        } 
        return dist[n-1][n-1];
    }
};
