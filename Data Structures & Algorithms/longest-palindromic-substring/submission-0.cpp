
class Solution {
public:
    int f(string &s, int i, int j, int n) {
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
        }

        return j - i - 1;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            int odd = f(s, i, i, n);
            int even = f(s, i, i + 1, n);

            int len = max(odd, even);

            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};
