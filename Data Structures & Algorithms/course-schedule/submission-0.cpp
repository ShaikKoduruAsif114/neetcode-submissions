class Solution {
public:


    bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&dfsvis){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(!dfs(it,adj,vis,dfsvis)) return false;
            }
            if(dfsvis[it]==1) return false;
            
        }
        dfsvis[node]=0;
        return true;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
                adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(numCourses,0);
        vector<int>dfsvis(numCourses,0);
        for(int i = 0;i<numCourses;i++){
            if(!vis[i]){
                if(!dfs(i,adj,vis,dfsvis)) return false;
            }
        }
        return true;
        

    }
};
