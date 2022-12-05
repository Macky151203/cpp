#include<iostream>
using namespace std;
struct datanode{
char data;
datanode *link;
};
struct headnode{
int count;
datanode *top;
};
class stack{
private:
headnode *stackhead;

public:
stack(){
stackhead = new headnode;
stackhead->count=0;
stackhead->top=NULL;
}
bool push(int datain){
datanode *t = new datanode;
t->data=datain;
t->link=stackhead->top;
stackhead->top=t;
stackhead->count++;

return true;
}
bool pop(){
int dataout;
bool success;
if(stackhead->count==0){
success=false;
}
else{
datanode *t =stackhead->top;
dataout=t->data;
stackhead->top=t->link;
stackhead->count--;
success=true;
delete t;
}
return success;
}
char  top(){
bool success;
char dataout;
if(stackhead->count==0){
success=false;
}
else{
dataout=stackhead->top->data;
// cout<<dataout<<endl;
success=true;
}
return dataout;
}
bool empty(){
bool empty;
if(stackhead->count==0){
empty=true;
}
else{
empty=false;
}
return empty;
}
bool destroystack(){
while(stackhead->top!=NULL){
datanode *t=stackhead->top;
stackhead->top=t->link;
delete t;
}
delete stackhead;
return true;
}

 void display(){
while(stackhead->top!=NULL){
datanode *t= stackhead->top;
cout<<t->data<<" ";
stackhead->top=t->link;
}
}
int prec(char c){
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}


};
stack s;
void itp(string sr){
string result;
for(int i=0;i<sr.length();i++){
char c=sr[i];
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'))
            result += c;
 
       
        else if (c == '(')
            s.push('(');
 
       
        else if (c == ')') {
            while (s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.pop();
        }else {
            while (!s.empty()
                   &&s.prec(sr[i]) <= s.prec(s.top())) {
                result += s.top();
                s.pop();
            }
            s.push(c);
        }
       
}
while (!s.empty()) {
        result += s.top();
        s.pop();
    }
 
    cout << result << endl;
}
int main(){




string st;
st="((a+b)/(c-d))+e";
itp(st);
return 0;




}