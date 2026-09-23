class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>>q;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(board[i][j]=='O') q.push({i,j});
                }
            }
        }
        vector<int>dx = {0,0,1,-1};
        vector<int>dy = {1,-1,0,0};
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            board[x][y] = 'B';
            for(int i = 0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n && board[nx][ny]=='O'){
                    q.push({nx,ny});
                }
            }
        }
        for(auto &it:board){
            for(auto &its:it){
                if(its=='O') its='X';
                else if(its=='B') its='O';
                else continue;
            }
        }
    }
};
