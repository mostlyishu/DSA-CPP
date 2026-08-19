#include <iostream>
using namespace std;

// Function to print duplicate characters with their count
void printDuplicates(string s) {
    if (s.size()==0)
    cout<<"string is empty"<<endl;

    int freq[26]={0}; // freq array of 26 size and all init with 0

    // now traverse the string s and recognise duplicates
    for(int i =0 ; i<s.size() ; i++){
         freq[s[i]-'a']++; // increase freq of every appearing alphabet by 1
    }
    
    // now recognise duplicates and print
    for (int i =0 ; i<26 ; i++){
         if (freq[i]>1){
            cout<<char('a'+i)<<" , "; //  char makes character from index again .. like 97 to a , 98 to b
         }
    }
    cout<<endl;
     
}

int main() {
    string s = "geeksforgeeks"; // e,g,k,s
    printDuplicates(s);
}