class Solution {
public:

    void f(int idx,vector<int>&nums,vector<int>&temp,int tempsum,set<vector<int>>&ans,int target,int n){
        if(tempsum>target) return ;
        if(idx==n){
            if(tempsum==target){
                ans.insert(temp);
            }
            return;
        }
        temp.push_back(nums[idx]);
        f(idx,nums,temp,tempsum+nums[idx],ans,target,n);
        temp.pop_back();
        f(idx+1,nums,temp,tempsum,ans,target,n);
    }



    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<vector<int>>st;
        vector<int>temp;
        f(0,nums,temp,0,st,target,nums.size());
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};
