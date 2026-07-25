class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        // think it like elections .. we will inc count for same candidate and dec count for diff
        // THIS IS BOYER-MOORE algorithm
        int candidate; // not initialised who is candidate
        int count=0; // initial count of unrecognised candidate

        // for every element nums[i]
        for ( int i =0; i<n ; i++){
           if (count == 0){ // used in starting or new candidate
           candidate = nums[i]; // make that ele as candidate
           count++; } // count is inc bcoz of first occurrence
           
           else if (nums[i]==candidate) 
            count++; // count is inc if same element is found (supporter)
           
           else 
           count--; // count is dec if different element (opponent) is found 

           
        } return candidate; // as count for this candidate would be >1 and hence it survived the elections
    }
}; //The majority element can never be completely cancelled because it appears more than all the other elements combined.