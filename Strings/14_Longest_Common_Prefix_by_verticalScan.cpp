class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) { // complexity : O(s)  
        // vertical scan match trick : match first word every character from start to all words same index character ... till unmatch in amongst the characters is found
        // compare strings vertically, character by character, column by column. Stop as soon as a mismatch occurs 
        
        for ( int i = 0 ; i<strs[0].length() ; i++){ // phle word ki length jitna outer loop .. charcter extract krne k liye h ye loop first word m se 
                 char ch = strs[0][i]; // character extract kia ek ek karke 
                 for (int j = 0 ; j<strs.size() ; j++){ // har word in vector k same index p jaane k liye loop
                    if (i>=strs[j].length() || ch != strs[j][i]){ // ya toh current word se extra h i index ya fr mismatch h 
                        return strs[0].substr(0,i); // to bs yehi ruk jao aur yehi tk ki substr return krdo as answer 
                    }
                 }
        }
        return strs[0]; // in case sare words bde the first word se aur no mismatch found h ... i.e. dono loop breaking condition nhi satisfy hui 
        // toh phle word hi ans h poora ka poora
    }
};