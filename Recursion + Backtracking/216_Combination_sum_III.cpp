class Solution {
public:
void getAllCombinations(vector<int>& candidates,int indx,int target,vector<int>& combin,vector<vector<int>>& ans , int count , int k ) {
         // Base case 1
        if (count == k && target == 0) { // target b bn gya h aur elements b exactly k use hue h toh ans valid h
            ans.push_back(combin); // add combinations to final ans 
            return;
        }

        // Base case 2
        if (count > k){ // combination bnante bnate humne k se zyda element leliye 
            return;
        }

        // Base case 3  // elements hi khtm hogye but target ni bna ya fr glt elements use krliye  h target -ve me chl gya 
        if (indx == candidates.size() || target < 0) // jese target = 4 , k =3 , [1,2,3] X
            return; 

        // Include current element in combin
        combin.push_back(candidates[indx]);

        getAllCombinations(candidates, indx + 1,target - candidates[indx], combin, ans , count+1 , k); // call mardo aage ki combination bnane ko

        // Backtrack
        combin.pop_back();

        // Exclude current element
        getAllCombinations(candidates, indx + 1, target, combin, ans , count , k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans; // to return all possible combin of k size 
        vector<int> combin; // to make one combin of k size
        vector<int> candidates = {1,2,3,4,5,6,7,8,9}; // nums to choose from
        int target = n;
        int count = 0; // to cal size of combin

        getAllCombinations(candidates, 0, target, combin, ans , count , k);

        return ans;
    }
};