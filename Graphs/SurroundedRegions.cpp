class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;

        for(int i = 0 ; i < m ; i ++){
            if(board[0][i]=='O'){
                board[0][i]='@';
                q.push({0,i});
            }
        }
        for(int i = 0 ; i < m ; i ++){
            if(board[n-1][i]=='O'){
                board[n-1][i]='@';
                q.push({n-1,i});
            }
        }
        for(int i = 0 ; i < n ; i ++){
            if(board[i][0]=='O'){
                board[i][0]='@';
                q.push({i,0});
            }
        }
        for(int i = 0 ; i < n ; i ++){
            if(board[i][m-1]=='O'){
                board[i][m-1]='@';
                q.push({i,m-1});
            }
        }
        int drow[4] = {1,0,-1,0};
        int dcol[4] = {0,1,0,-1};
        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();
            for(int i = 0 ; i < 4; i ++){
                int nr = row + drow[i];
                int nc = col + dcol[i];
                if(nr>=0 && nr < n && nc >=0 && nc < m && board[nr][nc] == 'O'){
                    q.push({nr,nc});
                    board[nr][nc]='@';
                }
            }
        }
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j]=='@'){
                    board[i][j] = 'O';
                }
            }
        }
        
    }
};
