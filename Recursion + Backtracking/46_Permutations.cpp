
class Solution {
public:
    void getPermutations(vector<int>& nums, int indx, vector<vector<int>>& ans) {

        // BASE CASE:
        // If indx reaches the size of the array,
        // we have successfully generated one permutation
        if (indx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Try placing every element at the current indx (khaali jgh) .. hum nums me inplace changes krre h .. usi m har bar ek permutation nikal k nums ko push krre h 
        for (int i = indx; i < nums.size(); i++) { 

            // STEP 1: Choose
            // Place nums[i] at the current index
            swap(nums[indx], nums[i]);

            // STEP 2: Explore
            // Recursively generate permutations for the remaining elements
            getPermutations(nums, indx + 1, ans);

            // STEP 3: Backtrack
            // Restore the original array so that we can try the next possible choice
            swap(nums[indx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;

        // Start generating permutations from indx 0
        getPermutations(nums, 0, ans);

        return ans;
    }
};

//                     [1,2,3]
//                        |
//            -------------------------
//            |           |           |
//         Fix 1        Fix 2       Fix 3
//            |           |           |
//         [1,2,3]     [2,1,3]     [3,2,1]
//            |           |           |
//          /   \       /   \       /   \
//         /     \     /     \     /     \
//  [1,2,3] [1,3,2] [2,1,3] [2,3,1] [3,2,1] [3,1,2]
