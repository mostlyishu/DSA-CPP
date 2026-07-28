class Solution {
public:
    void sortColors(vector<int>& nums) {
        // three pointers approach - low , mid , high
        // 0->low-1 = store 0s
        // low->mid-1 = store 1s
        // m->high = store unsorted array (ise khtm krna h kyuki ye ek extra section h gives while loop end logic)
        // high+1->nums.size()-1 = store 2s

        int low = 0; // to store 1s
        int high = nums.size()-1; // to stores 2s
        int mid = 0 ; // to check every element in unsorted array 

        while (mid <= high){
            if (nums[mid]==0){ // element is 0
             swap(nums[mid],nums[low]);
             low++; //for next position of 0s
             mid++; // for next element iteration
            }
            else if(nums[mid]==1){
                mid++; // skip 1s as mid-1 was storing 1 just move mid pointer ahead no need to swap
            }
            else {
                swap(nums[mid],nums[high]);
                high--; // new pos for 2s
                // mid shouldn't be inc as the new value at mid isn't processed yet by mid whether it is 0,1,2
            }
        }
    }
};