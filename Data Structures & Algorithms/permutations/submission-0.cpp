class Solution {
public:

    void f(vector<int>&nums,vector<bool>&vis,vector<int>&temp,vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return ;
        }
        for(int i = 0;i<nums.size();i++){
            if(vis[i]){
                continue;
            }
            vis[i] = true;
            temp.push_back(nums[i]);
            f(nums,vis,temp,ans);
            temp.pop_back();
            vis[i]=false;
        }
    }




    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>vis(nums.size(),false);
        f(nums,vis,temp,ans);
        return ans;
    }
};
