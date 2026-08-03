class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1 : sort the given 2d vector [[2,6],[1,3],[8,10],[15,18]]
         sort(intervals.begin(),intervals.end()); // to organise the intervals in line [[1,3],[2,6],[8,10],[15,18]]
        // Step 2 : answer vector to store answer
         vector<vector<int>> ans; 
        // Step 3 : push first interval [1,3]
        ans.push_back(intervals[0]); // no prev interval to check 
        // Step 4 : traverse from second interval [2,6],....
        for (int i =1 ; i<intervals.size() ; i++){
             // overlap ? check 
             if (intervals[i][0]<=ans.back()[1]){ // this means start of this interval is equal to or smaller than last interval end i.e. 2<=3 ? 
                  // update the interval stored in ans 
                ans.back()[1] = max(intervals[i][1],ans.back()[1]); // dono me se jo b max ho use ans k interval ka end bna do : max(3,6)
             }
             // else : gap h intervals me toh alg se push krdo [8,10],[15,18]
             else {
                   // push in asnwer 
                   ans.push_back(intervals[i]); // whole current interval : [1,6],[8,10],[15,18]
             }        
        }
        return ans;
    }
};