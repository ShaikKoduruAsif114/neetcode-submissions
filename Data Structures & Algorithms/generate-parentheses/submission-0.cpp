class Solution {
public:

    void f(int open,int close,string s,vector<string>&ans,int n){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            f(open+1,close,s+"(",ans,n);
        }
        if(close<open){
            f(open,close+1,s+")",ans,n);
        }
    }


    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string>ans;
        f(0,0,s,ans,n);
        return ans;
    }
};
