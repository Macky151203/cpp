#include<iostream>
#define MAX 5
using namespace std;
class Stack{
public:
int arr[MAX];
int top=-1;
bool push(int a){
bool success= true;

if((sizeof(arr)/4)>MAX){
success=false;
return success;
}
else{
++top;
arr[top]=a;
success=true;
return success;
}

}
bool pop(){
bool success= true;
int dataout;
if(sizeof(arr)==0){
success = false;

}
else{
dataout=arr[top];
--top;
success = true;

}
return success;

}
bool stacktop(int dataout){
bool success= true;

if(sizeof(arr)==0){
success=false;
return success;
}
else{
dataout=arr[top];
cout<<"dataout- "<<dataout<<endl;
success = true;
return success;
}
}
bool emptystack(){
bool empty;
if(top==-1){
empty=true;
return empty;
}
else{
empty=false;
return empty;
}
}
bool fullstack(){
bool full;
if(top==MAX){
full = true;
return full;
}
else{
full=false;
return full;
}
}
void display(){
for(int i=0;i<=top;i++){
cout<<arr[i]<<" ";
}
}


};
int main(){



int dataout;
bool a,b;

Stack p;
p.push(10);
p.stacktop(dataout);
p.push(11);
p.stacktop(dataout);
p.push(5);
p.stacktop(dataout);
p.pop();
p.stacktop(dataout);

a=p.fullstack();
b=p.emptystack();
if(a==true){
cout<<"stack is full"<<endl;
}
else{
cout<<"stack is not full"<<endl;
}
if(b==true){
cout<<"stack is empty"<<endl;
}
else{
cout<<"stack is not empty"<<endl;
}
p.display();





return 0;

}