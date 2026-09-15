class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int>ans;
        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n1){
            ans.push_back(nums1[i]);
                i++;
        }
        while(j<n2){
            ans.push_back(nums2[j]);
                j++;
        }
        int mid = (n1+n2)/2;
        if((n1+n2)%2==1){
            return (double)((ans[mid]));
        }else{
            return (double)( (double(ans[mid]) + double(ans[mid-1])) / double(2) );
        }
    }
};
