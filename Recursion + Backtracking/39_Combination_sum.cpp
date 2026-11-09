class Solution {
public:

set<vector<int>> unique; // set has been created to ignore same combinations again .. only return unique 

void getAllCombinations(vector<int>& candidates , int indx , int target , vector<int> &combin , vector<vector<int>> &ans){

    // base case 1
    if (indx == candidates.size() || target < 0) 
    return; // if indx goes out of array or our last included ele makes us surpass target 

    // base case 2
    if (target == 0){ // exact combination found 
        if (unique.find(combin) == unique.end()){ // find in unique (public set), if not found means doesn't already exists 
        ans.push_back(combin); // push in ans 
        unique.insert(combin); // also include in set so that to ignore future same combination
        }
        return;
    }

    // include curr ele single time 
    combin.push_back(candidates[indx]); // include and subtract from target and pass new target for call
    getAllCombinations(candidates , indx+1 , target-candidates[indx] , combin , ans); // indx++ as only one time we are including in this case 

    // include curr ele multiple times
    getAllCombinations(candidates , indx , target-candidates[indx] , combin , ans); // no need to update indx as we are including multiple times so next call also can include that ele 

    // backtrack and exclude curr ele
    combin.pop_back(); // remove the included ele

    // exclude this element 
    getAllCombinations(candidates , indx+1 , target , combin , ans); // only update indx without changing target

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> ans; // to return all combinations 
         vector<int> combin; // to  make combinations

         getAllCombinations(candidates , 0 , target , combin , ans ); // start from i 

         return ans;
    }
};