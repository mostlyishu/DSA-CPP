class Solution {
public:
    bool isValid(string s) {
        // can be solved using stack as this question is solved using LIFO order which is also used by stack 
        stack <char>stack; // stores character in one block 
        for (int i=0 ; i<s.size();i++){
            // two cases : if brakcet is of opening style 
            if (s[i]== '{' || s[i]== '[' || s[i]== '('){
                stack.push(s[i]); // push in stack 
            }
            else { // if bracket is of closing style
            // check if stack is empty 
                if (stack.empty())
                return false ; // no opening bracket appeared before ...hence stack was empty .. 
                // every closing bracket should have a opening bracket before it 
                if(s[i]=='}' && stack.top()=='{'){ //valid jodi bn gyi 
                    stack.pop();
                }
                else if (s[i]==')' && stack.top()=='('){ // matching pair : If current ) and top (
                    stack.pop();
                }
                else if (s[i]==']' && stack.top()=='['){
                    stack.pop();
                }
                else{ // if does not matches any return false
                    return false;
                }
            }
        }
        return stack.empty(); // true or false 
    }
};
// DRY RUN 
//           bracket
//              ↓
//        ┌─────┴─────┐
//        ↓           ↓
//    opening       closing
//        ↓           ↓
//      PUSH      stack empty?
//                    ↓
//               yes → false
//                    ↓ no
//              matching top?
//                ↓       ↓
//              yes       no
//               ↓         ↓
//             POP       false