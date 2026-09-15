class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int n = s.size();
        vector<int>freq(26,0);
        int maxfreq = 0;
        int ans = 0;
        for(int right = 0;right<n;right++){
            freq[s[right]-'A']++;
            maxfreq = max(freq[s[right]-'A'],maxfreq);
            while((right-left+1-maxfreq) > k){
                freq[s[left]-'A']--;
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};
