class Solution {
public:
    void getSubsets(vector<int>& nums, vector<int>&ishu , int i , vector<vector<int>> &himanshi ){
    // base case 
      if (i>=nums.size()){
          himanshi.push_back({ishu});
          return;
      }
    // recursive calls ; at every element we have two choices : include in ans or exclude 
    // include that element
     ishu.push_back(nums[i]);
     getSubsets(nums , ishu , i+1 , himanshi);
    // reset : undo : backtrack and go wps se upr ki call p 
    ishu.pop_back();
    // & exclude that element
    getSubsets(nums , ishu , i+1 , himanshi);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> himanshi; // all subsets pairs array
        vector<int>ishu; // single subset

        getSubsets(nums , ishu , 0 , himanshi);
        return himanshi;
    }
};