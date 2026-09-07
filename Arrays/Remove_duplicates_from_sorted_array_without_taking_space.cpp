#include <iostream> 
using namespace std ;
// remove duplicate elements (basically rearrange elements in place ) to get unique elements array
int countUnique(int *arr , int n ){ // t.c: O(n) ,s.c : O(1) 
    int i=0;            // this algo takes O(1) SC this is big thing 
    for ( int j=1; j<n ;j++){
        if (arr[i]!=arr[j]){
            i++; // shi position p jao 
            arr[i]=arr[j]; // wha p unique element rkh do
        }
    }
     return i; //i indx tk unique elements h array m but indx starts from 0
}

void print (int *arr , int indx ){
    for ( int i =0 ;i<=indx ; i++){
         cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr []= {1,1,2,3,3,4,5,5,5,5}; // sorted array with duplicates
    int n =sizeof(arr)/sizeof(int);
    int indx = countUnique(arr,n);
    cout<<"arr contains "<<indx+1<<" unique elements"<<endl;
    cout<<"printing unique elements array : "; 
    print(arr,indx);

}