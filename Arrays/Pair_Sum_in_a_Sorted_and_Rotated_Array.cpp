class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        int n = arr.size();
        
        if (n<2){
            return false; // one element can't form pair
        }
        // phle do pointer small and large rkho at break point
        // to find break point
        int i =0;
        while (i<n-1 && arr[i]<=arr[i+1]){ // to control i to don't go out of bound
            i++;
        }
        // large is now at i and small is at i+1;
        int large = i;
        int small = (i+1)%n;
        
        // move small and large to make sum accordingly in a circular array (imagined)
        while(small!=large){
            int sum = arr[small] + arr[large];
            
            if (sum==target){ // target found 
                return true;
            }
            
            else if (sum > target){ // large ko kam kro to dec sum
               large = (large - 1 + n) % n;
                // thid means -> large--;
                // -> if(large == -1) ... to handle circular iteration upper formula is written
                // -> large = n-1;
            }
            
            else { // small ko bdhao to inc sum
                small = (small + 1) % n;
              // this means -> small++;
                // -> if (small== n)
                // -> small = 0;
            }
        }
        return false;
    }
};\
=