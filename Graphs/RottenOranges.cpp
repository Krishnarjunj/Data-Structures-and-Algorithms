typedef long long int ll;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        ll n = grid.size();
        ll m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue <pair<pair<int,int> , int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i , j}, 0});
                }
                else{
                    vis[i][j]= grid[i][j];
                }
            }
        }

        ll drow[] = {1, 0 , -1, 0};
        ll dcol[] = {0, 1, 0 , -1};
        ll tm = 0;

        while(!q.empty()){
            ll nrow = q.front().first.first;
            ll ncol = q.front().first.second;
            ll t = q.front().second;
            q.pop();
            tm = max(tm , t);
            for(int i=0;i<4;i++){
                ll r = nrow + drow[i];
                ll c = ncol + dcol[i];
                if(r>=0 && r<n && c>=0 && c<m && vis[r][c]!=2 && grid[r][c]==1){
                    q.push({{r,c}, t+1});
                    vis[r][c]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1){
                    return -1;
                }
            }
        }
        return tm;
    }
};
