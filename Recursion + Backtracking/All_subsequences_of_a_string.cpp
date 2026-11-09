class Solution {
  public:
    void helper(string &s , vector<string> &ans , int i , string &subs){
        // base case 
        if (i>=s.length()){
            ans.push_back(subs);
            return;
        }
        // currently at i index in string  :
        // include this character 
        subs+=s[i];
        helper(s , ans , i+1 , subs);
        // exclude this character
        subs.pop_back();
        helper(s , ans , i+1 , subs);
    }
    vector<string> powerSet(string &s) {
        vector<string> ans;
        string subs = "";
        
        helper(s ,  ans , 0 , subs);
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};