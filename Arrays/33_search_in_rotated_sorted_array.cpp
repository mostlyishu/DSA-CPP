class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s =0;
        int e =nums.size()-1;
        while (s<=e){
            int mid = (s+e)/2;

            if (nums[mid]==target) // target found 
            return mid;

            // check if left half is sorted before mid
            if (nums[s]<nums[mid]){
                // target is possible in left half ?
                if (nums[s]<=target && target<nums[mid])
                e=mid-1; //right half array eliminated
                else // target must be in right half 
                s=mid+1; // left half array eliminated
            }
            // else right half is sorted 
            else {
                // target is possible in right half ?
                if (nums[mid]<target && target<=nums[e])
                s=mid+1; // left half array eliminated
                else  // target must be in left half
                e=mid-1; // right half array eliminated
            }
        }return -1; // not found 
    }
};