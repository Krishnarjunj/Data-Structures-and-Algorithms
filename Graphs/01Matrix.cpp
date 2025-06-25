class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n , vector<int>(m , -1));
        queue<pair<int,int>> q;

        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i , j});
                }
            }
        }
        int drow[4] = {1, 0 , -1 , 0};
        int dcol[4] = {0 , 1 , 0 , -1};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int i = 0 ; i < 4; i ++){
                int row = r + drow[i];
                int col = c + dcol[i];

                if(row>=0 && row < n && col>=0 && col<m && ans[row][col]==-1){
                    ans[row][col] = ans[r][c] + 1;
                    q.push({row, col});
                } 
            }
        }
        return ans;
    }
};
