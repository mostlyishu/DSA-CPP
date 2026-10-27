class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0; // to store max 
        int depth = 0; // to store curr 
        for ( int i =0 ; i<s.length() ; i++){
            char ch = s[i]; 
            if (ch == '('){ // if open inc depth 
               depth++;
               maxDepth = max(maxDepth , depth); // max ko update krdo yhi (not in else part : logical mistake hojaegi wrna kuch test case reh jayenge)
            }
            else if(ch == ')'){
                 depth--; // close bracket mila toh depth dec kro 
            }
        }
        return maxDepth; // return final ans
    }
};