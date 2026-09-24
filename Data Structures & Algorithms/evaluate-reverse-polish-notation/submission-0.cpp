class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto it:tokens){
            if(it!="+" && it!="-" && it!="*" && it!="/"){
                st.push(stoi(it));
            }
            else{
                int x2 = st.top();
                st.pop();
                int x1 = st.top();
                st.pop();
                if(it=="+"){
                    st.push(x1+x2);
                }
                else if(it=="-"){
                    st.push(x1-x2);
                }
                else if(it=="*"){
                    st.push(x1*x2);
                }else{
                    st.push(x1/x2);
                }
            }
        }
        return st.top();
    }
};
