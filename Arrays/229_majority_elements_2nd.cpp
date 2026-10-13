class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int candidate1 = 0, candidate2 = 0; // early stage 
        int count1 = 0, count2 = 0; // early stage votes
        for (int i =0 ; i<n ;i++){ // traverse array one by one 
        // Pass 1: Find two possible candidates 
        if (count1>0 && nums[i]==candidate1) // matches current candidate 1 (vote) .... order yehi rkhna h kyuki 
        // we must first check whether the current element already has a seat before assigning it a new seat.
        count1++; // increase the count 
        else if (count2>0 && nums[i]==candidate2) 
        count2++;
                 // pass 2 : vacant seats filling
        else if (count1 == 0){ // seat is vacant 
            candidate1 = nums[i]; // assign seat to curr ele
            count1 = 1;
        }
        else if (count2 == 0){ // seat is vacant 
            candidate2 = nums[i]; // assign seat to curr ele
            count2 = 1;
        }
          // totally diff element
        else {
            count1--;
            count2--;
        }
    }

        // reset count and recount and verify ( becoz in this algo sometimes the ans can be wrong )
        count1 = 0;
        count2 = 0;
        for ( auto x : nums){
            if (x == candidate1) // we got this candidate upr se
            count1++; 
            else if (x == candidate2) // we got this candidate from upr se 
            count2++;
        }

        // Add valid candidates to ans
        if (count1 > n/3) 
        ans.push_back(candidate1); // ans milgya
        if (count2 > n/3)
        ans.push_back(candidate2); // ans milgya

        return ans;
    
    } 
};