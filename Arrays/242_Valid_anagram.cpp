class Solution {
public:
    bool isAnagram(string s, string t) {
        // compare sizes
        if (s.size()!=t.size())
        return false;
        
        //create maps mp1 , mp2 for both string 
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        
        // feeding values in maps - value is intialised with 0 automatically
        for (int i =0 ; i<t.size() ; i++){
            mp1[s[i]]++;
            mp2[t[i]]++; // increase 0->1
        }

        //check the maps are equal ?
        if (mp1!=mp2)
        return false;

        return true;
    }
};