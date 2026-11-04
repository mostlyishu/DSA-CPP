class Solution {
public:
    string frequencySort(string s) {
        // create a map and store character freq in it (count each character freq)
        unordered_map<char,int>freqs;

        // traverse the string s and record the characters freq in it
        for ( auto ch : s){
            freqs[ch]++;
        }

        // now store map in char freq pairs vector
        vector<pair<char,int>>chars;
        for ( auto x : freqs){
            chars.push_back({x.first , x.second}); // x.first = character & x.second = uski freq
        }

        // sort chars according to the frequency using custom comparator (arrange char in dec count of freq)
        sort( chars.begin(),chars.end(), [](auto a ,auto b) { return a.second > b.second; }); // mtlb ki a aur b me se agr a bda h no change kro wrna swap krdo hence dec order 
         
        // now build the final ans string 
        string ans = "";
        for (int i =0 ;i<chars.size() ;i++){
            int freq = chars[i].second; // freq of of current char
            int count = 0; // to place char exactly freq count times
            while (count < freq){
                ans += chars[i].first; // curr char
                count++;
            } 
        }

        return ans;
    }
};