class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // build three vectors : leftproducts , rightproducts , ans 
        vector<int> leftproducts (n);
        vector<int> rightproducts (n); // option size n
        vector<int> ans (n);

        // 1,2,3,4,5
       // 1,1,2,6,24
       // 120,60,20,5,1
       //120,60,40,30,24

        // for every element calculate products of left elements from nums[i] and store at at index in leftproducts , also leftproducts[0] = 1 as there is no element behind first element in nums
        leftproducts[0]=1;
        for (int i=1 ; i<n ; i++){
              // isko smjho line ko, bhot shi line h 
             leftproducts[i]=leftproducts[i-1]*nums[i-1];
        }
        // ab humne leftproducts ki array ready krli
        // same right products ki b ready kro
        rightproducts[n-1]=1;
        for (int i=n-2 ; i>-1 ; i--){
             // isko smjho line ko ,bhot shi line h 
             rightproducts[i]=rightproducts[i+1]*nums[i+1];
        } 
        // dono arrays tyar
        // ab result array k liye simple step h 
        for (int i =0 ;i<n ; i++){
            ans[i]=leftproducts[i]*rightproducts[i];
        }
  return ans;
    }
};