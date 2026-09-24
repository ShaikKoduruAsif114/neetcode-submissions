class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i = 0;i<s.size();i++){
            if(st.empty()) {
                if(s[i]=='}' || s[i]==')' || s[i]==']') return false;
                st.push(s[i]);
            }
            else{
                if(s[i]=='}' || s[i]==')' || s[i]==']'){
                    char c = st.top();
                    if((s[i]=='}' && c=='{') || (s[i]==']' && c=='[') || (s[i]==')' && c=='(')){
                        st.pop();
                    }else{
                        return false;
                    }
                }else{
                    st.push(s[i]);
                }
            }
        }

        return st.empty();
    }
};
