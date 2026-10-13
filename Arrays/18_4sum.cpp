class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans; // to store quadruplets
        int n = nums.size();
        // sort the array
        sort(nums.begin(),nums.end());
        
        // fix one number
        for ( int i = 0 ; i<n-3 ; i++){ // n-3 bcoz baaki k bache hue element aage cover hore h 
        if ( i>0 && nums[i] == nums[i-1] ) // skip getting duplicate quadruplets as mentioned in question
        continue;
        // fix second number
            for ( int j = i+1 ; j<n-2 ; j++){ // bcoz baaki k bache hue ele pointers cover krenge 
            if ( j>i+1 && nums[j]== nums[j-1] ) // skip duplicate quadruplets
            continue;
                  int left = j+1; 
                  int right = n-1;
                  while (left < right){
                    long long sum = (long long)nums[i] + nums[j] + nums[right] + nums[left]; // to tackle if sum is very great
                    if (sum == target){
                        ans.push_back({nums[i],nums[j],nums[right],nums[left]});
                        right--; // ans milne k baad dono pointers move kro
                        left++;
                        while (left < right && nums[left] == nums[left - 1])
                            left++; // jbtk merko duplicate elements milte jaare h skip krte jao

                        while (left < right && nums[right] == nums[right + 1])
                            right--; // jbtk merko duplicate elements milte jaare h skip krte jao
                    }
                    else if (sum > target){
                        right--; // sum chota kro
                    }
                    else {
                        left++; // sum bda kro
                    }
                  }
            }
        }
        return ans; 
    }
};