class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i =0; //  ptr for scanning the array 
        int j =0; //  ptr for next pos for non zero ele

        while (i<nums.size()){
            if (nums[i]==0){
                i++;
            }
            else {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }
    } 
};