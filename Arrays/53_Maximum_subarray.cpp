class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum = 0 ; // calculate currentsum after adding each element x
        int maxsum = INT_MIN; // stores max value reached by currentsum

        for (int i =0 ; i<nums.size() ; i++){ // add one element one by one 
            currentsum = currentsum + nums[i]; 
            maxsum = max(currentsum,maxsum); // max value of current sum reched 
            // when a neg number is added the current sum decreases hence it's peak value is stored in maxsum
            if (currentsum<0){ 
                currentsum=0; // reset as we either don't want negative output or we want the output to be very less in negative
            }
        }
        return maxsum; // for test case {-5,-2,-3} , -2 is returned 
    }
};