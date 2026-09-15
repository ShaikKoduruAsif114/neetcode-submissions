class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int>s;
        int cnt = 1;
        int maxi = 1;
        for(auto it:nums){
            s.insert(it);
        }
        for(auto it:s){
            cnt = 1;
            int curr = it+1;
            if(!s.count(it-1)){
                while(s.count(curr)){
                    cnt++;
                    curr++;
                    maxi = max(maxi,cnt);
                }
            }
        }
        return maxi;
    }
};
