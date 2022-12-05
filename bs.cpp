#include<iostream>
using namespace std;
void bs(int arr[], int n){
    int current=0;
    bool sorted=false;
    int last=n-1;
    while(current<=last && sorted==false){
        sorted=true;
        int walker=last;
        int temp;
        while(walker>=current){
            if(arr[walker]<arr[walker-1]){
                temp=arr[walker-1];
                arr[walker-1]=arr[walker];
                arr[walker]=temp;
            }
            walker--;
        }
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
    bs(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
}