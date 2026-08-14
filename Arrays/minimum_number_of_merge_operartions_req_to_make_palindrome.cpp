// To find number of operations to make an array palindrome
#include <iostream>
using namespace std;
// Returns minimum number of count operations required to make arr[] palindrome
int findMinOps( int* arr , int  n){
  // init pointers : left and right 
  int left =0;
  int right =n-1;
  int ans = 0; // to count operations
  //start counting operations
    while (left <right){
           if (arr[left] == arr[right]){
            // no need of merge operation
            left++;
            right--;
           }
           else if (arr[left]<arr[right]){ // merge left side 
                  arr[left+1]=arr[left]+arr[left+1];
                  left++; // through this we are skipping the prev element ... works like delete 
                  ans++; // +1 operation
           }
           else {
            arr[right-1]=arr[right]+arr[right-1]; // merge right side
             right--;
             ans++;
           }
    }
    return ans;
}
// Driver program to test above
int main()
{
    int arr[] = {1, 4, 5, 5, 4, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
  cout << "minimum operations required : " <<  findMinOps(arr, n) << endl;
}