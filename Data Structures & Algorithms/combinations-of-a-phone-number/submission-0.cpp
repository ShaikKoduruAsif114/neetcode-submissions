class Solution {
public:

    void f(int idx,string digits,vector<string>&dig,string temp,vector<string>&ans){
        if(idx==digits.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0 ; i<dig[digits[idx]-'0'].size();i++){
            f(idx+1,digits,dig,temp + dig[digits[idx]-'0'][i],ans);
        }
    }




    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0) return ans;

        vector<string>dig(10);
        dig[2] = "abc";
        dig[3] = "def";
        dig[4] = "ghi";
        dig[5] = "jkl";
        dig[6] = "mno";
        dig[7] = "pqrs";
        dig[8] = "tuv";
        dig[9] = "wxyz";
        
        string temp = "";
        f(0,digits,dig,temp,ans);
        return ans;
    }
};
