#include<iostream>
using namespace std;
void toh(int start, int end, char src, char aux, char dest){
    if(start>end){
        return;
    }
    toh(start,end-1,src,dest,aux);
    cout<<"move disc "<<end<<"from "<<src<<"to "<<dest<<endl;
    toh(start,end-1,aux,src,dest); 

}
int main(){
    int n;
    cin>>n;
    toh(1,n,'a','b','c');
    return 0;


}