class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        vector<int>ans;
        int repeating=0; // to store repeating number
        for (int i=0; i<arr.size() ; i++){
            int currentval = abs(arr[i]); // fetch the value form array
            // find the index related to that value 
            int index=currentval-1; // for every i index there should be a element with val i+1;
            // visit index and see if it is negative then index+1 is the repeating element 
            if (arr[index]<0){
              repeating = currentval; // stored later in ans 
            }
            // else make that index elelement negative in array
            else 
            arr[index] *= -1; // marked negative in array ... hence visited
            
        }
        
        ans.push_back(repeating); // stored in ans
        
        // now to find the missing element 
        for ( int i=0;i<arr.size();i++){
            if (arr[i]>0){ // value is positive hence no index visited it ... so missing element is i+1
                ans.push_back(i+1);
                break; 
            }
        }
        return ans;
    }
};