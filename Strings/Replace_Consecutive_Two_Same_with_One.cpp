class Solution { // remove duplicates from a string and inly add one from duplicates 
  public:
    string removeDuplicates(string& s) {
        // Step 1 : make a empty string to store every valid character
        string ans="";
        
        if (s.size()==0) // if input string is empty
        return ans; // return empty ans immediately
        
        // otherwise traverse the input string by taking two pointers
        int prev = 0 ; 
        int curr = 1 ;
        while (curr<s.size()){
            // curr matches prev : move both pointers forward 
            if (s[curr]==s[prev]){
                curr++;
                prev++; // move both forward 
            }
            else{
                ans.push_back(s[prev]); // add prev character in ans string
                curr++;       // ans = ans + s[prev] takes long time and hence gives TLE here due to repeated 
                prev++;       // string construction
            }
        }
        // add last character alag se finally 
        ans.push_back(s[prev]); 
        return ans;
    }
};