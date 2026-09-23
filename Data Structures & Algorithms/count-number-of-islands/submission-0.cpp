class Solution {
public:

    void dfs(int i , int j , vector<vector<char>>&grid,vector<vector<bool>>&vis){
        

        vis[i][j] = true;
        vector<int>x = {0,0,1,-1};
        vector<int>y = {1,-1,0,0};
        for(int k = 0;k<4;k++){
            int nx = i + x[k];
            int ny = j + y[k];
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny] == '1'){
                if(!vis[nx][ny]){
                    dfs(nx,ny,grid,vis);
                }
            }
        }
        return;
    }


    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int cnt = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;

    }
};
