#include<iostream>
using namespace std;
struct datanode{
    int data;
    datanode *link;
};
struct headnode{
    int count;
    datanode *top;
};
class linkedstack{
    headnode *stackhead;
    public:
        linkedstack(){
            stackhead = new headnode;
            stackhead->count=0;
            stackhead->top=NULL;
        }
        bool push(int data){
            datanode *t= new datanode;
            t->data=data;
            t->link= stackhead->top;
            stackhead->top=t;
            stackhead->count++;
            return true;
        }
        bool pop(){
            int dataout;
            if(stackhead->count==0){
                return false;
            }
            else{
                datanode *t = stackhead->top;
            dataout= t->data;
            stackhead->top=t->link;
            stackhead->count--;
            delete t;
            return true;
            }
        }
        bool stacktop(int dataout){
            if(stackhead->count==0){
                return false;
            }
            else{
                dataout=stackhead->top->data;
                cout<<dataout<<endl;
                return true;
            }
        }
        bool empty(){
            if(stackhead->count==0){
                return true;
            }
            else{
                return false;
            }
        }
        bool destroystack(){
            while(stackhead->top!=NULL){
                datanode *t= stackhead->top;
                stackhead->top=t->link;
                delete t;
            }
            delete stackhead;
            return true;
        }
        void display(){
            datanode *t = stackhead->top;
            do{
                cout<<t->data<<" ";
                t=t->link;
            }while(t!=NULL);
        }
};
int main(){
linkedstack s;
int choice,dataout,data,again;
cout<<"enter 1 to push, 2 to pop, 3 to stacktop, 4 to emptystack, 5 to destroystack, 6 to display "<<endl;
do{
cout<<"enter choice ";
cin>>choice;
switch(choice){
case 1:
cout<<"enter elem to be pushed- ";
cin>>data;
if(s.push(data)){
cout<<"element pushed "<<endl;
}
break;
case 2:
if(s.pop()){
cout<<"element poped"<<endl;
}
break;
case 3:
s.stacktop(dataout);break;
case 4:
if(s.empty()){
cout<<"stack is empty"<<endl;
}break;
case 5:
if(s.destroystack()){
cout<<"stack destroyed "<<endl;
}break;
case 6:
s.display();
break;
default:
cout<<"enter valid "<<endl;


}cout<<"enter 1 to continue and 0 to end";
cin>>again;
}while(again);

return 0;
}