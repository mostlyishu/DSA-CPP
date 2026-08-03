class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // take three pointers at i = last valid element in nums1 , j= last element in nums2
        // k = last space in nums1
        int i = m - 1; 
        int j = n - 1; 
        int k = m + n - 1;
        while (j>=0){
               if (i>=0 && nums1[i]>=nums2[j]){ //i>=0 to handle m=1 and n=0 case
                nums1[k]=nums1[i];
                k--;
                i--;
               }
               else { // either i<0 or nums1[i]<nums2[j]
                nums1[k]=nums2[j];
                k--;
                j--;
               }
        }
    }
};