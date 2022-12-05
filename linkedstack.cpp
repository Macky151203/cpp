#include<iostream>
using namespace std;
// struct stackhd{
//     public:
//     int count=0;
//     stackhd *top;
// };
struct Node{
    public: 
    int data;
    Node *link;

};
Node *top;
void push(int a){   
     Node *temp = new Node();
    
    temp->data=a;
    temp->link=top;
    top=temp;
    cout<<"pushed"<<endl;

    
}
int main(){
   
push(2);
return 0;


}