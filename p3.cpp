#include<iostream>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    int sum=0;
    int max=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
            cin>>arr[i][j];
        }
    }
    
    for(int i=0;i<m;i++){
        sum=0;
        for(int j=0;j<n;j++){
            
            sum+=arr[i][j];
        }

        if(sum>max){
            max=sum;
           
        }
        
    }
    cout<<sum;
    return 0;
   
}