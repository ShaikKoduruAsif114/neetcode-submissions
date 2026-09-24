class Solution {
public:

class DisjointSet{
public:
    vector<int>parent;
    vector<int>rank;
    DisjointSet(int n){
        parent.resize(n);
        rank.assign(n,0);
        for(int i = 0;i<n;i++){
            parent[i]=i;
        }
    }
    int findUpar(int x){
        if(parent[x]==x) return x;
        return parent[x]=findUpar(parent[x]);
    }
    void unionByRank(int x,int y){
        int x_par = findUpar(x);
        int y_par = findUpar(y);
        if(x_par==y_par) return;
        if(rank[x_par]<rank[y_par]){
            parent[x_par] = y_par;
        }
        else if(rank[x_par]>rank[y_par]){
            parent[y_par]=x_par;
        }else{
            parent[y_par]=x_par;
            rank[x_par]++;
        }
    }
};



    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int maxi = 0;
        for(auto it:edges){
            maxi = max(max(it[0],it[1]),maxi);
        }
        DisjointSet DS(maxi+1);
        int ans1,ans2;
        for(auto it:edges){
            if(DS.findUpar(it[0])==DS.findUpar(it[1])){
                ans1 = it[0];
                ans2 = it[1];
            }
            DS.unionByRank(it[0],it[1]);
        }
        return {ans1,ans2};
    }
};
