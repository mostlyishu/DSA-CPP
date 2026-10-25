class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = ""; // to store ans 
        int depth = 0 ; // to check outermost brackets :
        // opening = 0->1  , closing = 1->0
         
        for ( int i =0 ; i<s.length() ;i++){ // iterate on every character of string s
            char ch = s[i];
            if (ch == '('){ // if open bracket 
                if (depth>0){ // and if depth >0 i.e. 1,2,3... then it is of our use 
                    ans += ch; // add in ans string 
                }
                depth++; // iska mtlb ki depth bdha do ... works for differentiating outermost bracket
            }
            else {
                depth--; // phle kam kro ... jisse 0->1 jaye toh pta chl outermost closing bracket h 
                if (depth>0){ //  if depth fr b h toh ans m include kro
                    ans += ch;
                }
            }
        }
        return ans;
    }
};