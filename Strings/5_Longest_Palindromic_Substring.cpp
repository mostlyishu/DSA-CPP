class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0; // to keep starting index of largest palindromic string 
        int maxLen = 1; // to keep length of largest palindromic string

        for (int i = 0; i < n; i++) { // iterate at every character of s

     // 1. Odd-length palindrome (for every i .. check both odd and even)
            int left = i; // as assumed ODD then centre is i and expand from there
            int right = i; // keep at i for odd

            while (left >= 0 && right < n && s[left] == s[right]) { // jab tak out of bounds ni hota 
            // ya fr charcter mismatch ni hota exapand kro from centre
                left--; 
                right++;
            }

            // Update start and maxLen
            int len = right - left - 1;  // dry run this formula

            if (len > maxLen) { // if the curr len is grater then only update these to find ans later
                maxLen = len;
                start = left + 1; // as left would be now on either out of bounds or on mismatch char
            }

     // 2. Even-length palindrome
            left = i; // left at i
            right = i + 1; // right at i+1 ..., centre between them "bb".. centre is between both b's

            while (left >= 0 && right < n && s[left] == s[right]) { // check same condition
                left--;
                right++;
            }

            // Update start and maxLen
            len = right - left - 1; 

            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        }

        return s.substr(start, maxLen); // start gives ans starting index and maxLen give len to cut 
    }
};