class Solution {
public:
    int lengthOfLongestSubstring(string s) { // sliding window approach 
    // Expand right. If duplicate appears, move left until the window becomes valid again
        int left = 0 ; // sbse phle character of string pe rkha left pointer
        int maxlen = 0; // store krega max length of noo repeating substring
        int freq[256]={0}; // 256 character freq array as s[i] can be anything look at constraint
        for (int right =0 ; right<s.size() ; right++){ // right ko aage bdhao first se
            freq[s[right]]++; // new character h aage bdhao
            while (freq[s[right]]>1){ // duplicate characters mila h is loop m enter hojao ab
                freq[s[left]]--; // aap left ko aage toh bdhao ab (window aage bdhao) but jo b left p character aare h 
                left++; //unki freq kam kro kyuki abi wo humari valid window m nhi h 
            }
            maxlen = max(maxlen , right-left+1); // ab max update kro 
            // right - left hoyegi valid substring window size but +1 isliye kyuki left wale ya right wale kisi b ek element ko substring m include krlo
        }
       return maxlen; // return krdo (returns 0 in case of empty input string) as for loop never executes 
    }
};
//Right enters the window , If it creates a duplicate , we move left , Left removes characters from the window , Once the window becomes valid ;We record its size.
// also For a string of length n, left can move at most n times. And right can also move at most n times.
// but left doesn't starts fresh every time hence and only moves forward by 1 step so it can take utmost n steps 
// hence TC: O(n+n) = O(2n) = O(n) 
// left doesn't moves n times for every right it only moves total n time no relation with right 