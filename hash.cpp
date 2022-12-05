#include <iostream>
#define MAXSIZE 10
using namespace std;
struct datanode
{
    int data;
    datanode *link;
};
struct Headnode
{
    int count;
    datanode *first;
};
class hashing
{
private:
    Headnode *hashtable[10];

public:
    hashing()
    {
        
        int walker = 0;
        
        while (walker < 10)
        {
            hashtable[walker] = new Headnode; 

            hashtable[walker]->count = 0;
            hashtable[walker]->first = NULL;
            walker++;
            
        }
    }

    bool insertintohash(int key)
    {
        
        datanode *t = new datanode;
        t->data = key;
        
        

        int hashindex = key % MAXSIZE;
        t->link = hashtable[hashindex]->first;
        hashtable[hashindex]->first = t;
        hashtable[hashindex]->count += 1;
        
        return true;
    }
    bool deletefromhash(int key)
    {
        int hashindex = key % MAXSIZE;
        datanode *delnode = hashtable[hashindex]->first;
        datanode *pred = NULL;
        while (delnode != NULL)
        {
            if (delnode->data == key)
            {
                if (pred == NULL)
                {
                    hashtable[hashindex]->first = delnode->link;
                }
                else
                {
                    pred->link = delnode->link;
                }
                hashtable[hashindex]->count -= 1;
                return true;
            }
            pred = delnode;
            delnode = delnode->link;
        }
        
        return false;
    }
    bool search(int key, int locn)
    {
        int hashindex = key % MAXSIZE;
        datanode *searchnode = hashtable[hashindex]->first;
        while (searchnode!= NULL)
        {
            if (searchnode->data == key)
            {
                locn = hashindex;
                return true;
            }
            searchnode = searchnode->link;
        }
        return false;
    }
    void display()
    {
        int walker = 0;
        while (walker < MAXSIZE)
        {
            datanode *temp = hashtable[walker]->first;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->link;
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