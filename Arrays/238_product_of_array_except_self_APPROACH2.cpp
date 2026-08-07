class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       // APPROACH WITH O(N) TC AND O(1) SC (better optimised uses less space)
        int n = nums.size();
        vector <int>ans(n); // takes no extra space as we return it in the end
        ans[0]=1; 
        for (int i =1 ; i<n ; i++){
            ans[i] = ans[i-1]*nums[i-1];
        }
        // left product array is now stored in ans array hence took no extra space 
        // now we will not find right product array , we will use a var suffixproduct and iterate from last and hence directly produce ans array by using suffixproduct

        int suffixproduct = 1;
        for (int i = n-1 ; i>=0 ; i--){
             ans[i]=ans[i]*suffixproduct; // update i index of ans = left products(ans)*rightproduct(suffixproduct)
             suffixproduct*=nums[i]; // this will be used for next iteration of i
        }
         return ans ;
    }
};