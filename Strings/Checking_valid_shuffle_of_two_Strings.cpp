#include <iostream>
using namespace std;

bool validShuffle(string &str1, string &str2, string &shuffle)
{

    // n1 = size of str1, n2 = size of str2
    int n1 = str1.size();
    int n2 = str2.size();

    // n = size of string shuffle
    int n = shuffle.size(); 

    // Its obvious if the no. of char in shuffle are more or less than the length of str1 and str2 then it won't be a valid shuffle
    if (n != n1 + n2)
        return false; 

    unordered_map<char, int> freq;

    // Count frequency of each char in str1
    for (int i = 0; i < n1; i++)
        freq[str1[i]]++;

    // Count frequency of each char in str2
    for (int i = 0; i < n2; i++)
        freq[str2[i]]++;
    // now check shuffle string
    for (int i = 0; i < n; i++) {
        if (freq.find(shuffle[i]) != freq.end()) // returns true or false 
            freq[shuffle[i]]--; // uski freq ghata do 
        else
            return false; 
    }

    // Checks whether all the elements's frequency in
    // hashmap becomes 0
    for (auto it = freq.begin(); it != freq.end(); it++) {
        if (it->second != 0) {
            return false;
        }
    }
    return true;
}


int main()
{
    string str1 = "BA", str2 = "XY", shuffle = "ABYX";
    if (validShuffle(str1,str2,shuffle))
    cout<<"Valid shuffle"<<endl;
    else 
    cout<<"INVALID shuffle"<<endl;

}