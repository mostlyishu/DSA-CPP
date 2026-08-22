class Solution {
public:
    int maxArea(vector<int>& height) {
        // two pointers approach O(n)
        int lp = 0 , rp = height.size()-1; // left pointer and right pointer at 0 and n-1
        int maxwaterstored = INT_MIN;

        while (lp<rp){  
            int width = rp-lp; // width =  index diff 
            int riseheight = min(height[rp],height[lp]); // min decides the rise level
            int currWater = width * riseheight; // 
            maxwaterstored = max(maxwaterstored,currWater); // update max water

            if (height[lp]<height[rp]){ // this means lp is making stored water small by itself being small wall
                lp++; // hence lp aage bdhao
            }
            else { // this means rp is making stored water small by itself being small wall
                rp--; // right ptr ko piche lao
            }
        }
        return maxwaterstored; // last me final answer return krdo 
    }
};