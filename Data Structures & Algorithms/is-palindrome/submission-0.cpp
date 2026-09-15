class Solution {
public:
    bool alphanumeric(char c){
        return ((c >= 48 && c <= 57) || 
                (c >= 65 && c <= 90) || 
                (c >= 97 && c <= 122));
    }

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while(i < j){
            while(i < j && !alphanumeric(s[i])) i++;
            while(i < j && !alphanumeric(s[j])) j--;
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
