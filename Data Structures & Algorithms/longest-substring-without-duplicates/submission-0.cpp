class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int n = s.size();
        int ans = 0;
        map<char,int>mpp;
        for(int right = 0;right<n;right++){
            mpp[s[right]]++;
            while(mpp[s[right]]>1){
                mpp[s[left]]--;
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};






