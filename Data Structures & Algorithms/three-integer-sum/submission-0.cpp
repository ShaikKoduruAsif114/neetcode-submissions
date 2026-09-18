class Solution {
public:

    vector<pair<int,int>>2sum(vector<int>&nums,int i,int target){
        vector<pair<int,int>>ans;
        
        int left = 0;
        int right = nums.size()-1;
        while(left<right){
            if(i==left){
                left++;
            }
            if(i==right){
                right--;
            }
            if(nums[left]+nums[right]==target){
                ans.push_back({nums[left],nums[right]});
            }
            else if(nums[left]+nums[right]<target){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i<n;i++){
            vector<pair<int,int>>temp=2sum(nums,i,-1*nums[i]);
            for(auto it:temp){
                ans.push_back({nums[i],it.first,it.second});
            }
        }
        return ans;
    }
};
