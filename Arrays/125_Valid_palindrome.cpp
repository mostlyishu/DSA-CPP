class Solution {
public:
    bool isPalindrome(string s) { 
        int i =0; 
        int j =s.size()-1;
        while(i<j){
            // to skip non alphanumeric characters logic is if not upper case & lower case & digit .. skip it
            if ( ! (s[i]>='a' && s[i]<='z') &&  ! (s[i]>='A' && s[i]<='Z') && ! (s[i]>='0' && s[i]<='9') ){
                i++;
                continue;
            } // to move i when it points non- alphanumeric character

            if ( ! (s[j]>='a' && s[j]<='z') && ! (s[j]>='A' && s[j]<='Z') && ! (s[j]>='0' && s[j]<='9') ){
                j--;
                continue;
            } // to move j backwards when it points non- alphanumeric character
            
            // to convert upper case into lower case letters
            if (s[i]>='A' && s[i]<='Z'){
                s[i]=s[i]+32;   // upper case + 32 = lower case
            }
            if (s[j]>='A' && s[j]<='Z'){ // upper case to lower case
                s[j]=s[j]+32;
            }
            
            // to check palindrome
            if (s[i] != s[j])
            return false;
            i++;
            j--;
        } 
        return true;
    }
};