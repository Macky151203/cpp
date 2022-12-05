#include<iostream>
using namespace std;

struct cricinfo{
    string pname;
    string country;
    int age;
    int matches;
};
class cricket{
    public:
    bool rlinearsearch( cricinfo ci[],int index,int last,string target){
        if(index>last){
            return false;
        }
        else if(target==ci[index].country){
            cout<<"name- "<<ci[index].pname<<endl;
           return  rlinearsearch(ci,index+1,last,target);
        }
        else{
            return rlinearsearch(ci,index+1,last,target);
        }
    }
    void getinput(cricinfo ci[],int n){
        for(int i=0;i<n;i++){
            cout<<"age- ";
            cin>>ci[i].age;
            cout<<"country- ";
            cin>>ci[i].country;
            cout<<"name- ";
            cin>>ci[i].pname;
            cout<<"matches total- ";
            cin>>ci[i].matches;
        }
    }
};
int main(){
    int n;
    cout<<"enter n- ";
    cin>>n;
    cricinfo ci[n];
    cricket c;
    c.getinput(ci,n);
    c.rlinearsearch(ci,0,n,"india");
    return 0;

}