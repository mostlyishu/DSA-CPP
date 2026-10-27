class Solution {
public:
    int numberOfSubstrings(string s) {
        int n =s.length();
        int count = 0 ; // to store ans
        int left =0; // left pointer 
        int a=0, b=0 ,c=0;
        for ( int right =0 ; right<n ; right++ ){ // right ko shuru kia 0 index se 
            if (s[right] == 'a') a++; // a bdha dia 
            else if (s[right] == 'b') b++; // b bdha dia 
            else c++; // c bdha dia 

            while (a>0 && b>0 && c>0){ // if a , b , c teeno h toh : 

                count = count + (n - right); // curr count me (n - right) plus krdo kyuki if this window 
                //contains a,b,c then expanding right all window will contain i.e. all right expansions are valid

                if (s[left] == 'a') a--; // ab left ko process krna shuru kro // ek aage bdhao aur fr se check kro while ki 
                else if (s[left] == 'b') b--; // condtion ; if true then uske aage ki saari right ki window ans me plus krdo
                else c--;

                left++;
            }

        }
        return count;
    }
};