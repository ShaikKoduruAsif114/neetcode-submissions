// class Solution {
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
//     }
// };





class Solution {
public:

    void f(int idx,vector<int>&nums,vector<int>&temp,int tempsum,vector<vector<int>>&ans,int target,int n){
        if(tempsum==target){
            ans.push_back(temp);
        }
        for(int i = idx;i<n;i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(tempsum + nums[i]>target) break;
            temp.push_back(nums[i]);
            f(i+1,nums,temp,tempsum+nums[i],ans,target,n);
            temp.pop_back();
        }
    }



    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        f(0,nums,temp,0,ans,target,nums.size());
        return ans;
    }
};
