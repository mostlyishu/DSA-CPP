class Solution {
public:
    int majorityElement(vector<int>& nums ) {
        unordered_map < int , int> mp ; // key -> element , value -> freq.
        int n = nums.size();
        for (int i =0 ; i<n ; i++){  // iterate through every element
                 mp[nums[i]]++; // increase the frequency count by 1

                 if (mp[nums[i]] > n/2) // check immeaditaley if this element repetition is more than half of size of array(n)
                 return nums[i]; // element which repeated(value) more than > n/2 (equal is not included)

        } return -1; // written just to tackle compilation error ( satisfy the compiler)
        // never executed because of question's conditions 
    } 
}; // we can also later find the most high freq. (value) in map and return the element corresponding to it (key)