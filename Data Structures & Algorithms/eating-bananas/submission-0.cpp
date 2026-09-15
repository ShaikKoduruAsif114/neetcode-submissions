class Solution {
public:

    int time(vector<int>&piles,int k){
        int sum = 0;
        for(auto it:piles){
            sum += (it+k-1)/k;
        }
        return sum;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        int ans = 0;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(time(piles,mid)<=h) {
                ans = mid;
                right = mid-1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};
