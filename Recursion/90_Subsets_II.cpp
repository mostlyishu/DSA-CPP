class Solution {
public:
    void getSubsets(vector<int>& nums, vector<int>&ishu , int i , vector<vector<int>> &himanshi ){
    // base case 
      if (i>=nums.size()){
          himanshi.push_back(ishu);
          return;
      }
    // recursive calls ; at every element we have two choices : include in ans or exclude 
    // include that element
     ishu.push_back(nums[i]);
     getSubsets(nums , ishu , i+1 , himanshi);
    // reset : undo : backtrack and go wps se upr ki call p 
    ishu.pop_back();
    // now to skip duplicate subsets we need to exclude all nums[i] duplicates while excluding along with nums[i]
    int indx = i+1; // nums[i] skipped through this line
    while (indx < nums.size() && nums[indx] == nums[i]) { indx++; } // all duplicates of nums[i] skipped
    getSubsets(nums , ishu , indx , himanshi);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> himanshi; // all subsets pairs array
        vector<int>ishu; // to make single subset

        getSubsets(nums , ishu , 0 , himanshi);
        return himanshi;
    }
};