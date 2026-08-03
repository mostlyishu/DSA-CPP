class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map < int , int > mp; // unordered_set<int> st; (hash set can also be used with only key)
        for ( int i =0 ; i<nums.size() ; i++){
            if (mp.find(nums[i]) != mp.end()){ // use find function to find the current element ( key ) in map mp
                return true; // found           st.find(nums[i]) for hash set
            }
             
              mp[nums[i]]=1; // feed the element
        
        }
        return false; // not found (feeded all element)
    }
};