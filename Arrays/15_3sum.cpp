class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        // sort first as this helps a lot 
        sort (nums.begin(),nums.end());

        // now fix one element that is i and then make this problem find pair sum with target in sorted array , so find j and k 
        for (int i =0 ; i<nums.size() ; i++){
            // skip duplicate i ... if one element has been fixed in tiplet making one time .., skip it's duplicates
            if (i>0 && nums[i]==nums[i-1]){
                continue; // we have already checked for ans using this element
            }
            int left = i+1; // i k just baad se array kat do
            int right = n-1;

            while (left < right){
                int sum = nums[i]+nums[left]+nums[right]; 
                // check sum with target 
                if (sum==0){
                    // store answer
                      ans.push_back({nums[i],nums[left],nums[right]}); // for 2d vector push ve push in 1d vector format
                      // move both pointers
                      left++; 
                      right--;
                     //  handle duplicates like avoid again pointing left or right on duplicate element
                     while (left<right && nums[left]==nums[left-1]){
                        left++; // skip duplicate 
                     }
                     while (left<right && nums[right]==nums[right+1]){
                        right--; // skip duplicate
                     }
                }
                else if (sum < 0){
                    left++; // left ko aage bdhao ... jisse sum ki value bdhe aur 0 ko reach ho 
                }
                else {
                    right--; // right ko kam kro jisse sum ki value kam ho aur 0 ko reach ho
                }
            }
        }
        return ans;
    }
};