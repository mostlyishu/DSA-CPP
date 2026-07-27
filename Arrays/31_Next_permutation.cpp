class Solution {
public:
    void nextPermutation(vector<int>& nums) { // for ex: {2,5,8,7,6,1}
        // start from the right (pointer at last) to find the pivotele which breaks the strictly increasing order
        int pivotele;
        int pivotindex =-1; // for the case 3,2,1 ... it should return 1,2,3 as next permutation ,hence reverse
        for (int i = nums.size()-2 ; i>=0 ; i--){ 
              // look for pivot i.e from right the number should increase if a number decreases that's the pivot ele
             if (nums[i]<nums[i+1]){
             pivotele = nums[i]; // {2,[5],8,7,6,1}
             pivotindex = i;   // here 1
             break; // to come out of loop after getting very first pivot 
             }
             }
         
        // if no pivot found in the whole array , simply reverse the array to get next permutation
        if (pivotindex==-1)
        reverse(nums.begin(),nums.end());

       // else find the smallest number greater than pivotele in it's right  
       // as the suffix of pivotele is stictly dec hence we can iterate from last and compare to get index : {2,[5],8,7,6,1}
       else { int tempindex; 
        for (int i = nums.size()-1 ; i>pivotindex ; i--){ 
            if (nums[i]>pivotele)
            { tempindex = i ; //  index of smallest number in pivot suffix [6]-> 4
            break; // to come out of the loop
              } 
        }
        // swap the pivot with smallest element
        swap(nums[pivotindex],nums[tempindex]); // nums[1],nums[4]
        // now reverse everything after the pivot to get the very next permutation : {2,1,5,6,7,8}
        reverse(nums.begin()+pivotindex+1 , nums.end());
             }
    }
};