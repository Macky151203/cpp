#include<iostream>
using namespace std;

struct datanode{
    int data;
    datanode *link;
};
struct headnode{
    int count;
    datanode *head;
};


class linkedlist{
    private:
        headnode *list;
        datanode *ppre,*ploc;
    public:
        linkedlist(){
            list = new headnode;
            list->count=0;
            list->head=NULL;
            ppre=NULL;
        }
        bool insertnode(int datain){
            datanode *pnew = new datanode();
            pnew->data=datain;
            if(ppre==NULL){
                pnew->link=list->head;
                list->head=pnew;
                
               
            }
            else{
                pnew->link=ppre->link;
                ppre->link=pnew;
                
            }
            list->count++;
            cout<<"inserted elem ";
            return true;
        }
        bool deletenode(){//ploc the node to be deleted
            int dataout;
            dataout = ploc->data;
            if(ppre==NULL){
                list->head=ploc->link;

            }
            else{
                ppre->link=ploc->link;
            }
            list->count--;
            cout<<"deleted elem";
            return true;
        }
        bool search(int target){
            ppre=NULL;
            ploc=list->head;
            while(ploc!=NULL && target > ploc->data){
                ppre=ploc;
                ploc=ploc->link;
            }
            if(ploc==NULL){
                return false;
            }
            else{
                if(target==ploc->data){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        bool addnode(int data){
            
            bool res;
            res=search(data);
            if(res){
                cout<<"cannot insert dup";
                return false;
            }
            else{
                insertnode(data);
                return true;
            }
            
        }
        bool removenode(int data){
            bool r;
            r=search(data);
            if(r){
                deletenode();
                return true;
            }
            else{
                cout<<"data not there";
                return false;
            }
        }
        void display(){
            datanode *temp= list->head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->link;
            }
        }
};
int main(){
    linkedlist ll;
    ll.addnode(5);
    ll.addnode(10);
    ll.addnode(15);
    ll.removenode(10);
    ll.addnode(12);
    ll.display();
}