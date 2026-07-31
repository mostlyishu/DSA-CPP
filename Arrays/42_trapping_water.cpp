class Solution {
public:
    int trap(vector<int>& height) {
        int totalwater =0;
        // approach : find min of rightmax and leftmax of an bar and hence find the riselevel which is minimum
        // of leftmax and rightmax ,, now find the waterunit stored above that bar but if riselevel<currentbar then 
        // water can't be stored hence -ve value is obtained , so take max of waterunit to generate valid answer
        // do this same for every bar except last and first bar as they don't have next and prev  (need two wall for storage)
        for (int i = 1 ; i<height.size()-1 ; i++){
                // find left max for this element 
                int leftmax = -1;
                for (int j=0 ; j<i ; j++ ){
                    leftmax = max(leftmax,height[j]);
                }
                // find right max for the element 
                int rightmax = -1;
                for (int j=i+1 ; j<height.size() ; j++ ){ // full right array is seen
                    rightmax = max(rightmax,height[j]);
                }
                // water rises upto minimum of right max and left max 
                int riselevel = min(leftmax,rightmax);
                // now calculate this particular ele water unit
                int waterunit = riselevel - height[i]; 
                // for negative water holding for this element we take max with 0
                waterunit = max (0, waterunit); // current bar is already taller than the riselevel
                // now add units for current element in totalwater
               totalwater += waterunit;
        }
        return totalwater;
    }
};