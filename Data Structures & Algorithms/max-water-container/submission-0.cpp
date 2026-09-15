class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n-1;
        int maxi = 0;

        while(i<j){
            maxi = max(maxi,min(heights[i],heights[j])*(j-i));
            if(heights[i]<heights[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxi;
    }
};
