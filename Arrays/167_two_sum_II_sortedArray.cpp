class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       int i = 0;
       int j = numbers.size()-1;
       vector<int>ans;
       
       while (i<j){
        int pairSum = numbers[i]+numbers[j];
        if (pairSum < target){
            i++ ; // chote element starting m h unhe bdhane ki jrurat h 
        }
        else if (pairSum > target){
            j--; // bde element last me h unhe kam krne ki jrurat h 
        }
        else { // pairSum == target
             ans.push_back(i+1);
             ans.push_back(j+1); // as we have to return incremented index in ques.
             return ans;
            }
       }
       return ans;
    }
};