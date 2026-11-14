class Solution {
public:
    void helper(string digits, unordered_map<int,string> mapping,
                vector<string>& ans, string output, int indx) {

        // Base case: Jab saare digits process ho jaayein
        if (indx >= digits.length()) {
            ans.push_back(output); // Complete combination ko answer vector mein store kar do
            return;
        }

        // Current digit nikalo (Example: "23" mein pehle 2 milega)
        int number = digits[indx] - '0';

        // Current digit ke corresponding saare letters mapping se nikalo
        // Example: Agar number 2 hai, toh letters "abc" milenge
        string letter = mapping[number];

        // Current digit ke har possible letter ko ek-ek karke try karo
        for (int i = 0; i < letter.length(); i++) {

            char ch = letter[i]; // Current letter select karo (a, then b, then c)

            output.push_back(ch); 
            // Selected letter ko current combination mein add karo

            helper(digits, mapping, ans, output, indx + 1);
            // Next digit ke letters process karne ke liye recursive call
            // Example: "2" ke liye a select hua, toh ab "3" ke letters try honge
            // Isse "ad", "ae", "af" jaise combinations banenge

            output.pop_back();
            // Backtracking: Last added letter remove karo
            // Taaki next letter ko try karte waqt purana combination restore ho jaaye
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;    // Saare possible combinations store karne ke liye
        string output;         // Ek combination step-by-step banane ke liye

        // Phone keypad ke digits aur unke corresponding letters ki mapping
        unordered_map<int,string> mapping;

        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        // Index 0 se recursion start karo
        helper(digits, mapping, ans, output, 0);

        // Saare possible combinations return karo
        return ans;
    }
};