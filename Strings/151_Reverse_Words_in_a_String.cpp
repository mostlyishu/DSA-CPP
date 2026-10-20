class Solution {
public:
    void reverseAlgo(string &s){
        int i = 0;
        int j = s.size() - 1;
        while (i < j){
            swap(s[i], s[j]); // reverse the string 
            i++;
            j--;
        }
    }
    
    string reverseWords(string s) {
        string ans;
        // 1. Reverse the whole string
        reverseAlgo(s);

        string temp = ""; // to build a valid word 

        // 2. Extract and reverse each word
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                temp = temp + s[i]; 
            } 
            // Only process temp if we hit a space AND temp is not empty i.e. temp conatains a word (handles multiple spaces)
            else if (temp != "") {
                reverseAlgo(temp);
                ans = ans + temp + ' ';
                temp = "";
            }
        }
        
        // 3. Handle the very last word after the loop finishes
        if (temp != "") {
            reverseAlgo(temp);
            ans = ans + temp; // last word processed
        }
        
        // 4. Clean up any trailing space if the string ended with spaces
        if (ans != "" && ans.back() == ' ') {
            ans.pop_back(); // if sentence k baad last me space h toh handle ho gya
        }
        
        return ans;
    }
};