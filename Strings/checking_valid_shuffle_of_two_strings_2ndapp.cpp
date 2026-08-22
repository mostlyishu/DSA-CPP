#include <iostream>   // THIS PROBLEM STATEMENT HAS SLIGHT CHANGES : MORE LIKE 97 INTERLEAVING STRINGS
// Valid Shuffle of Two Strings → Backtracking (without changing the original order while choosing characters from s1 and s2 )
using namespace std ;
bool isValid(string &s1,string &s2,string &shuffle,int i, int j){
    int k =i+j;
    
    //base case ..(both strings s1 and s2 are succesfully completely consumed by shuffle string)
    if (i==s1.size() && j==s2.size()){
        return true;
    }
    
    // ek case smbhal lete h 
    // ya toh shuffle ka kth character s1 se choose hoga 
    if (i<s1.size() && s1[i]==shuffle[k]){ // i valid index h aur ith character of s1 is matching with kth character of shuffle
        if (isValid(s1,s2,shuffle,i+1,j)) // ye choose krke usse shuffle bnao but i+1 krdo ... last tak path dhundho
        return true; // mil jaye last tak toh return krdo true
    }
    // ya toh shuffle ka kth character s2 se choose hoga 
    if (j<s2.size() && s2[j]==shuffle[k]){ // j valid index h aur jth character of s2 is matching with kth character of shuffle
        if (isValid(s1,s2,shuffle,i,j+1)) //// ye choose krke usse shuffle bnao but j+1 krdo ... last tak path dhundho
        return true; // mil jaye last tak toh return krdo true
    }

    // agar dono s1 and s2 se hum shuffle ka character ni choose kr paye toh invalid string hai return krdo false
    return false;


}
bool solve(string &s1,string &s2,string &shuffle){
     if (s1.size()+s2.size()!=shuffle.size()) // cannot be a valid shuffle 
     return false;

     return isValid(s1,s2,shuffle,0,0); 
}
int main (){
    // INPUT
    string s1 = "ab", s2 = "acd", shuffle = "aabcd";
   if (solve(s1,s2,shuffle)){
    cout<<"VAlID shuffle"<<endl;
   }
   else {
        cout<<"INVALID shuffle"<<endl;
   }

}