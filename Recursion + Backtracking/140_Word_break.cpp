class Solution {
public:

    void helper(string s, vector<string>& wordDict, int start,vector<string>& temp, vector<string>& ans) {

        // Agar poori string break ho gayi
        // temp mein ek complete sentence ready hai
        if (start == s.size()) {

            string sentence = "";

            // temp ke words ko space ke saath join karo
            for (int i = 0; i < temp.size(); i++) {
                sentence += temp[i];

                if (i != temp.size() - 1)
                    sentence += " ";
            }

            ans.push_back(sentence);
            return;
        }

        string current = "";

        // start se word banana start karo
        for (int i = start; i < s.size(); i++) {

            current += s[i];

            // Check karo current word dictionary mein hai ya nahi
            bool found = false;

            for (auto word : wordDict) {
                if (word == current) {
                    found = true;
                    break;
                }
            }

            if (found) {

                // Word select karo
                temp.push_back(current);

                // Next word i+1 se search karo
                helper(s, wordDict, i + 1, temp, ans);

                // Backtrack: current word hatao
                // aur next possibility try karo
                temp.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        vector<string> ans;   // saare possible sentences
        vector<string> temp;  // current sentence ke words

        helper(s, wordDict, 0, temp, ans);

        return ans;
    }
};