class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // sort the array 
        // After sorting, the optimal answer will always be a contiguous window of size m.
        sort(a.begin(),a.end());
        
        int ans = INT_MAX; // to find min diff
        for (int i =0 ; i < a.size()-m+1 ; i++){ // last window size = arr.size()-(m-1) as i starts from 0
            int diff = a[i+m-1]-a[i]; // diff bw first and last element of sorted window of arr.size()-(m-1) size
            ans = min(ans,diff); // store min ans of every window
        }
        return ans;
    }
};