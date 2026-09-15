class Solution {
public:
    int findMin(vector<int> &arr) {
        int left = 0;
        int right = arr.size()-1;
        int n = arr.size();
        int ans = INT_MAX;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(arr[mid]>=arr[0]){
                ans = min(ans,arr[0]);
                left = mid + 1;
            }else{
                ans = min(arr[mid],ans);
                right = mid-1;
            }
        }
        return ans;
    }
};
