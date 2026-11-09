
class Solution {
public:
    void getAllCombinations(vector<int>& candidates,int indx,int target,vector<int>& combin,vector<vector<int>>& ans) {

         // Base case 1 ... combination maked target
        if (target == 0) {
            ans.push_back(combin); // add combinations to final ans 
            return;
        }

        // Base case 2
        if (indx == candidates.size() || target < 0) // ya toh elements khtm ho gye ya fr target 
            return; // hi negative me chla gya toh aage bdhne ka fayda ni

        // Include current element in combin
        combin.push_back(candidates[indx]);

        getAllCombinations(candidates, indx + 1,target - candidates[indx], combin, ans); // call mardo aage ki combination bnane ko

        // Backtrack
        combin.pop_back();

        // Skip duplicates while excluding
        while (indx + 1 < candidates.size() &&
               candidates[indx] == candidates[indx + 1]) { // if koi element use ni kia toh uski koi b occurence use ni krenge sb exclude krenge 
            indx++; // unique combinations bola h na ques me isliye .. ek baar exclude kia toh kia .. if khi bola jaye all combinations wha p excluded 
            // ki recursion branch me use fr se include kr skte h aage b .. but yha nai kr skte ek baar krdia toh aage kbi b 
        }

        // Exclude current element
        getAllCombinations(candidates, indx + 1, target, combin, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombinations(candidates, 0, target, combin, ans);

        return ans;
    }
};
