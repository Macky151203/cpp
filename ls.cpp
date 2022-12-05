#include<iostream>
using namespace std;
// class createstack{
//     public:
//     int count=0;
    

// };
class Node{
    public:
    int data;
    int count=0;
    Node *link;
    Node *top=nullptr;
     

    
    void push(int a){
        Node *t= new Node();
        
        
        t->data=a;
        t->link=top;
        top=t;
        cout<<"pusherd"<<endl;
        count++;
        cout<<count<<endl;
    }

};
int main(){
    Node n;
    n.push(2);
    n.push(3);
    return 0;

}

