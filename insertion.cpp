#include<iostream>
using namespace std;
void is(int arr[],int n){
    int  current=1;
    while(current<n){
        int hold;
        int walker=current-1;
        hold=arr[current];
        while(walker>=0 && hold<arr[walker]){
            arr[walker+1]=arr[walker];
            walker--;
        }
        arr[walker+1]=hold;
        current++;
    }
}
int main(){
    int n;
    
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    is(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}