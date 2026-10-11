class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i = 0;i<n;i++){
            dp[i][i] = true;
        }
        for(int i=n-1;i>=0;i--){
            for(int j = i;j<n;j++){
                if(s[i]==s[j]){
                    if(j-i+1 <= 3 || dp[i+1][j-1]){
                        dp[i][j]=true;
                    }
                }
            }
        }
        int cnt = 0;
        for(auto it:dp){
            for(auto its:it){
                if(its) cnt++;
            }
        }
        return cnt;
    }
};
