class Solution {
public:
    bool isMatch(vector<int>& pFreq, vector<int>& windowFreq) {
        for (int i = 0; i < 26; i++) {
            if (pFreq[i] != windowFreq[i]) // agar mismatch in both arrays mila khi b toh false 
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans; // to store starting indices

        int n = s.length();
        int m = p.length();

        if (m > n)
            return ans; // empty array return krdo .. no possible ans

        vector<int> pFreq(26, 0);
        vector<int> windowFreq(26, 0);

        // 1. Count characters in p
        for (int i = 0; i < m; i++) {
            pFreq[p[i] - 'a']++; // learn this formula for lower case letter to index array
        }

        // 2. Build the first window of length m
        for (int i = 0; i < m; i++) {
            windowFreq[s[i] - 'a']++; // marked the array for forst window char
        }

        // 3. Slide the window through s
        int left = 0;

        for (int right = m - 1; right < n; right++) { // left -> right ki window = p.length();

            if (isMatch(pFreq, windowFreq)) { // agar curr window makes both arrays match then push left ka index into ans as we need only starting index
                ans.push_back(left);
            }

            // Remove outgoing character
            windowFreq[s[left] - 'a']--; // ek character for bhr nikalo sath hi uska count b kam krdo in window -1 se ... iss step se harr bar new window array bnane ki jrurat nai h 

            left++; // window aage bdhao

            // Add the next incoming character, if one exists
            if (right + 1 < n) {
                windowFreq[s[right + 1] - 'a']++; // nya char add krdo right se 
            }
        }

        return ans;
    }
};