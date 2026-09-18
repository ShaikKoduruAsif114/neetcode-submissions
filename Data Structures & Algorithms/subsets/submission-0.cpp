class Solution {
public:

    void f(vector<int>&nums,int idx,vector<int>&temp,set<vector<int>>&ans,int n){
        if(idx==n){
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[idx]);
        f(nums,idx+1,temp,ans,n);
        temp.pop_back();
        f(nums,idx+1,temp,ans,n);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>st;
        vector<int>temp;
        f(nums,0,temp,st,nums.size());
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};
