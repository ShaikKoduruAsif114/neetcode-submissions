class Solution {
public:
    
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<pair<int,int>>q;
        vector<int>vis(n,0);
        int cnt=0;
        for(int i = 0;i<n;i++){
            if(vis[i]==1) continue;
        q.push({i,-1});
        cnt++;
        vis[i]=1;

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto it:adj[node.first]){
                if(vis[it]==0){
                    q.push({it,node.first});
                    vis[it]=1;

                }
                else{
                    if(it!=node.second) return false;
                }
            }
        }
        }
       
        return cnt==1;
    }
};
