class Solution {
public:
    bool ispermutation(string s1,string s2){
        map<char,int>mpp;
        for(auto it:s1){
            mpp[it]++;
        }
        for(auto it:s2){
            mpp[it]--;
        }
        for(auto it:mpp){
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        int left = 0;
        int right = s1.size()-1;
        while(right<s2.size()){
            string temp = s2.substr(left, s1.size());
            if(ispermutation(s1,temp)){
                return true;
            }
            left++;
            right++;
        }
        return false;

    }
};
