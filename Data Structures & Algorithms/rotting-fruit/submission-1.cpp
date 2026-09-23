class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
            }
        }
        vector<vector<int>>time(m,vector<int>(n,INT_MAX));
        int mini = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int curr = node.first;
            int x = node.second.first;
            int y = node.second.second;
            vector<int>dx = {0,0,1,-1};
            vector<int>dy = {1,-1,0,0};
            for(int i = 0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1 && curr+1<time[nx][ny]){
                    time[nx][ny] = curr+1;
                    mini = max(mini,curr+1);
                    q.push({curr+1,{nx,ny}});
                }
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1 && time[i][j]==INT_MAX){
                    return -1;
                }
            }
        }
        return mini;

    }
};
