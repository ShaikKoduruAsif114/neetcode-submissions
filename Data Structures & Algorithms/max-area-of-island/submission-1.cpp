class Solution {
public:
   

    int dfs(int i, int j, vector<vector<int>>&grid, vector<vector<bool>>&vis){
        vis[i][j] = true;
        int cnt = 1;
        vector<int>x = {0,0,1,-1};
        vector<int>y = {1,-1,0,0};
        for(int k = 0;k<4;k++){
            int nx = i + x[k];
            int ny = j + y[k];
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && !vis[nx][ny] && grid[nx][ny]==1){
                cnt += dfs(nx,ny,grid,vis);
            }
        }
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
         int maxi = 0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    maxi = max(maxi , dfs(i,j,grid,vis));
                }
            }
        }
        return maxi;
    }
};
