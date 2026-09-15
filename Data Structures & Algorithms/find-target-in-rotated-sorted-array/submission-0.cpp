class Solution {
public:
    int search(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(arr[mid]==target){
                return mid;
            }
            if(arr[mid]>=arr[0]){
                if(target<=arr[mid] && target>=arr[0]){
                    right = mid-1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if(target>=arr[mid] && target<=arr[arr.size()-1]){
                    left = mid + 1;
                }else{
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};
