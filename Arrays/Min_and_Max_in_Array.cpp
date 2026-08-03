class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for (int i =0 ; i<arr.size() ; i++){
            maxi = max(arr[i],maxi);
            mini = min(arr[i],mini);
        }
        vector<int>ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        
        return ans;
        
    }
};