#include<iostream>
using namespace std;
struct datanode{
    int data;
    datanode *link;
};
struct headnode{
    int count;
    datanode *first;
};
class hashing{
    
    headnode *hashtable[10];
    public:
        hashing(){
            int walker =0;
            while(walker<10){
                hashtable[walker]= new headnode;
                hashtable[walker]->count=0;
                hashtable[walker]->first=NULL;
                walker++;
            }
        }
        bool insertintohash(int key){
            int hashindex= key%10;
            datanode *t= new datanode;
            t->data=key;
            t->link=hashtable[hashindex]->first;
            hashtable[hashindex]->first=t;
            hashtable[hashindex]->count++;
            return true;
        }
        bool deletefromhash(int key){
            int hashindex= key%10;
            datanode *pred=NULL;
            datanode *delnode = hashtable[hashindex]->first;
            while(delnode!=NULL){
                if(delnode->data==key){
                    if(pred==NULL){
                        hashtable[hashindex]->first=delnode->link;
                        
                    }
                    else{
                        pred->link=delnode->link;
                        
                    }
                    hashtable[hashindex]->count--;
                    return true;
                }
                pred=delnode;
                delnode=delnode->link;
            }
            return false;
        }
        bool search(int key,int locn){
            int hashindex= key%10;
            datanode *searchnode= hashtable[hashindex]->first;
            while(searchnode!=NULL){
                if(searchnode->data==key){
                    locn=hashindex;
                    return true;
                }
                searchnode=searchnode->link;

            }
            return false;

        }
        void display(){
            int walker = 0;
            
            while(walker<10){
                datanode *t= hashtable[walker]->first;
                while(t!=NULL){
                cout<<t->data<<" ";
                t=t->link;
                }
                walker++;
            }
        }
};
int main()
{
hashing h;
int choice,data,i=1,locn=-1;
bool result;
while(i==1)
{
cout<<"\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter choice:";
cin>>choice;
switch(choice)
{
case 1:
cout<<"Enter the element you want to insert:";
cin>>data;
result=h.insertintohash(data);
if (result==1)
    cout<<"Inserted into hash table successfully.";
break;
case 2:
cout<<"Enter the element you want to delete:";
cin>>data;
result=h.deletefromhash(data);
if (result==0)
    cout<<"Element is not found.";
else
{
cout<<"Deleted element:"<<data<<endl;
            cout<<"Deleted from hash table successfully." ;
}
break;
case 3:
cout<<"Enter the element you want to search:";
cin>>data;
result=h.search(data,locn);
if (result==0)
  cout<<"Element is not found.";
else
cout<<"Element is present at index "<<locn<<"."<<endl;
break;
case 4:
h.display();
break;
    default:
i=0;
}
}
}
