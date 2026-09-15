
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        int cnt = 0;

        map<char, int> mpp;

        for (auto it : t) {
            mpp[it]++;
            cnt++;
        }

        int n = s.size();
        int ans = s.size() + 1;
        int target = 0;

        while (right < n) {

            if (mpp[s[right]] > 0) {
                cnt--;
            }

            mpp[s[right]]--;

            while (cnt == 0) {

                if (right - left + 1 < ans) {
                    target = left;
                    ans = right - left + 1;
                }

                mpp[s[left]]++;

                if (mpp[s[left]] > 0) {
                    cnt++;
                }

                left++;
            }

            right++;
        }

        if (ans == s.size() + 1) {
            return "";
        }

        return s.substr(target, ans);
    }
};