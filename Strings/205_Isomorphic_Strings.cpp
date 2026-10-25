class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // if length diff .. return false immediately
        if (s.length() != t.length())
            return false;

        // create two vectors for 256 characters
        vector<int> sTot(256, -1); // for all ascii char nd all init with -1
        vector<int> tTos(256, -1);

        // iterate through s and t
        for (int i = 0; i < s.length(); i++) {
            char a = s[i]; //  a is char from s
            char b = t[i]; //  b is char from t 

            // if character has been mapped already
            if (sTot[(unsigned char)a] != -1 || // a is mapped or b is mapped to some char then 
                tTos[(unsigned char)b] != -1) {

                // both mappings must match
                if (sTot[(unsigned char)a] != (int)(unsigned char)b ||  // if a -> b se matched nai h toh false 
                    tTos[(unsigned char)b] != (int)(unsigned char)a) //  ya fr b-> a se mapped nai h toh b false
                    return false; 
            }
            else {
                // map a to b and b to a
                sTot[(unsigned char)a] = (unsigned char)b; // new mapping h wrna krdo map a ko b se aur b ko a se ... bidirectional mapping
                tTos[(unsigned char)b] = (unsigned char)a; 
            }
        }

        return true;
    }
};