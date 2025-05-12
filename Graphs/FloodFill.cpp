typedef long long int ll;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        ll n = image.size();
        ll m = image[0].size();
        queue <pair<ll,ll>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j] = image[i][j];
            }
        }
        ll a = vis[sr][sc];
        vis[sr][sc] = color;
        q.push({sr,sc});
        ll drow[] = {1, 0 , -1 , 0};
        ll dcol[] = {0 , 1 , 0 , -1};
        while(!q.empty()){
            ll nr = q.front().first;
            ll nc = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                ll r = nr + drow[i];
                ll c = nc + dcol[i];
                if(r>=0 && r<n && c>=0 && c<m
                && vis[r][c]!=color && image[r][c]==a){
                    q.push({r,c});
                    vis[r][c] = color;
                }
            }
        }
        return vis;        
    }
};
