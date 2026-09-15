class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        
        for(auto it:nums){
            mpp[it]++;
        }
        vector<pair<int,int>>v(mpp.begin(),mpp.end());
        sort(v.begin(),v.end(),[](pair<int,int>a,pair<int,int>b){
            return a.second>b.second;
        });
        int i = 0;
        vector<int>ans;
        while(k--){
            ans.push_back(v[i].first);
            i++;
        }
        return ans;
    }
};
