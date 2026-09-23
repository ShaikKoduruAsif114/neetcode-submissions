class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int>q;
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        vector<int>ans;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i]==0) {q.push(i);
            ans.push_back(i);}
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        if(ans.size()==numCourses) return ans;
        return {};
    }
};
