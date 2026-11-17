class Solution {
public:

    // Check karta hai ki s[i...j] palindrome hai ya nahi
    // Palindrome = left se aur right se same read ho
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    // start = jis index se abhi partition karna start karna hai
    // temp  = current partition ka combination
    // ans   = saare valid combinations
    void helper(string s, int start, vector<string>& temp, vector<vector<string>>& ans) {

        // BASE CASE: Agar start string ke end tak pahunch gaya,
        // iska matlab poori string successfully partition ho gayi
        if (start == s.length()) {
                // Current valid partition ko answer mein store karo
            ans.push_back(temp);
            return;
        }

        // start se lekar string ke end tak har possible substring try karenge
        // Example:
        // s = "aab" , start = 0
        // i = 0 → "a" , i = 1 → "aa" , i = 2 → "aab"
        for (int i = start; i < s.size(); i++) {

            // Check karo ki s[start...i] palindrome hai ya nahi
            if (isPalindrome(s, start, i)) {

                // Current palindrome substring ko store kro
                temp.push_back(s.substr(start, i - start + 1));

                // Ab baaki string ko partition karo , i tak substring choose kar liya hai,
                // isliye next partition i+1 se start hogi
                // Example:
                // "aa" | "b"
                //       ↑
                //      i+1
                helper(s, i + 1, temp, ans);


                // BACKTRACK: Jo substring abhi choose ki thi, use remove karo taaki next possible substring try kar sakein
                temp.pop_back();
            }
        }
    }


    // Main function
    vector<vector<string>> partition(string s) {

        // Current partition store karne ke liye
        vector<string> temp;

        // Saare valid partitions store karne ke liye
        vector<vector<string>> ans;


        // String ke index 0 se partitioning start karo
        helper(s, 0, temp, ans);


        // Saare valid palindrome partitions return karo
        return ans;
    }
};