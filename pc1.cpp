#include<iostream>
using namespace std;
struct pi{
    string gender;
    string name;
    int age;
    string bg;
};
class patientinfo{
    public:
    void getinput(int n, pi p[]){

        for(int i=0;i<n;i++){
            cout<<"age";
            cin>>p[i].age;
            cout<<"gender";
            cin>>p[i].gender;
            cout<<"name";
            cin>>p[i].name;
        }
    }
    bool binarysearch(int a,int n, pi p[]){
       
        int mid;
        int start=0;
        int end=n;
        while(start<=end){
            mid=(start+end)/2;
            if(p[mid].age>a){
                start=mid+1;
            }
            else if(p[mid].age<a){
                end=mid-1;
            }
            else{
                start=end+1;
            }
            

        }
        if(p[mid].age==a){
                if(p[mid].gender=="male"){
                    
                    cout<<p[mid].name<<endl;
                    return true;
                }
            }
            else{
                return false;
            }
    }
};
int main(){
    int n;
    cout<<"enter n- ";
    cin>>n;
    pi p[n];
    patientinfo pat;
    pat.getinput(n,p);
   if( pat.binarysearch(10,n,p)){
    cout<<"success";
    
   }
   else{
    cout<<"not foubd";
   }
   return 0;
}