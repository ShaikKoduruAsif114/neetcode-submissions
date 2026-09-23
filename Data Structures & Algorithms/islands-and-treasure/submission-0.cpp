class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dist(m,vector<int>(n,2147483647));
        queue<pair<int,pair<int,int>>>q;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({0,{i,j}});
                }
            }
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int dis = node.first;
            int x = node.second.first;
            int y = node.second.second;
            vector<int>dx = {0,0,-1,1};
            vector<int>dy = {1,-1,0,0};
            for(int i = 0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]!=0 && grid[nx][ny]!=-1 && dis+1<dist[nx][ny]){
                    dist[nx][ny] = dis + 1;
                    grid[nx][ny] = dis+1;
                    q.push({dis+1,{nx,ny}});
                }
            }
        }
        return;
    }
};
