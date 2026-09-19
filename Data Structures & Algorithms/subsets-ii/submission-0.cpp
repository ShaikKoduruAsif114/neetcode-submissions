class Solution {
public:

    void f(int idx,vector<int>&nums,vector<int>&temp,set<vector<int>>&ans){
        if(idx==nums.size()){
            ans.insert(temp);
            return;
        }
        // temp.push_back(nums[idx]);
        // f(idx+1,nums,temp,ans);
        // temp.pop_back();
        // f(idx+1,nums,temp,ans);
        for(int i = idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            f(i+1,nums,temp,ans);
            temp.pop_back();
            f(i+1,nums,temp,ans);
        }
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        set<vector<int>>st;
         f(0,nums,temp,st);
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};
