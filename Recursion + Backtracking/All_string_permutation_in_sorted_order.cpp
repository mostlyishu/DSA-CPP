class Solution {
public:
    void helper(string s, string perm, vector<string>& ans) {

        // Base case 
        // ab sari remaining(input) string khtm ho gyi h ... mtlb sb kuch fix hogya h given places p
        if (s.length() == 0) {
            ans.push_back(perm);
            return;
        }

        for (int i = 0; i < s.length(); i++) { // ek ek character choose kro for current position
        // baaki recursion ko dedo

            char ch = s[i]; 

            // Remove the selected character from string and send further to recursion
            string remStr = s.substr(0, i) + s.substr(i + 1); // substr (indx , len) or substr(indx)= indx se last tk

            // Recursive call
            helper(remStr, perm + ch, ans); // remstr pass krdo agle recursion me 
            // permutation me curr fixed selected ele ko add krdo 
        }
    }

    vector<string> permutation(string& s) {

        vector<string> ans;

        helper(s, "", ans);
        sort(ans.begin(),ans.end());

        return ans;
    }
};