class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        int cnt = 0;
        map<char,int>mpp;
        for(auto it:t){
            mpp[it]++;
            cnt++;
        }
        int n = s.size();
        int ans = s.size()+1;
        int target = 0;
        while(right<n){
            
            if((mpp.find(s[right])!=mpp.end()) && mpp[s[right]]>0){
                cnt--;
            }
            mpp[s[right]]--;
            if(cnt==0){
                while(mpp[s[left]]<0){
                    left++;
                }
                if(right-left+1<ans){
                target = left;
                ans = right-left+1;
            }
            }
            
            right++;
        }
        if(ans == s.size()+1){
            return "";
        }
        return s.substr(target,ans);
        
    }
};
