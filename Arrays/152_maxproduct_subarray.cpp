class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prevMax = nums[0];
        int prevMin = nums[0]; //prevMax and prevMin can be init with 1 also but loop then should start from i=0
        int ans = nums[0];   // to store overall max product (for only one element in nums ... ans should be that element)
        for (int i = 1 ; i<nums.size() ; i++){
            // nums[i] ko curr bnao
            int curr = nums[i];
           //currmax calculate kro 
           int currMax = max(curr,max(prevMax*curr,prevMin*curr));

           //currMin calculate kro
           int currMin = min(curr,min(prevMax*curr,prevMin*curr));

           // now update ans
           ans = max(currMax,ans);

           // prevMax aur prevMin ko update kro jisse unhe aage agle element p use kr sko
           prevMax= currMax;
           prevMin= currMin;

        }
        return ans;
    }
};