#include<iostream>
using namespace std;
const int MAX_SIZE=10;
struct datanode
{
int data;
datanode *link;
};
struct headnode
{
int count;
datanode *first;
};
class HashTable
{
headnode *hashTable[MAX_SIZE];
public:
HashTable()
{

int walker=0;
while(walker < MAX_SIZE)
{
hashTable[walker]=new headnode;
hashTable[walker]->count=0;
hashTable[walker]->first=NULL;
walker++;
}
}
int hash(int key)
{
return (key%MAX_SIZE);
}
bool insertToHashTable(int key)
{
int hashIndex=hash(key);
cout<<hashIndex;
datanode *T=new datanode;
T->data=key;
T->link=hashTable[hashIndex]->first;
hashTable[hashIndex]->first=T->link;
hashTable[hashIndex]->count++;
return true;
}
bool deleteFromHashTable(int& dltKey)
{
int hashIndex=hash(dltKey);
cout<<hashIndex;
datanode *delNode=hashTable[hashIndex]->first;
datanode *pred=NULL;
while(hashTable[hashIndex]->count!=0)
{

if (delNode->data==dltKey)
{

if (pred==NULL)
hashTable[hashIndex]->first=delNode->link;
else
pred->link=delNode->link;
hashTable[hashIndex]->count--;
return true;
}

pred=delNode;
delNode=delNode->link;

}
return false;
}
bool searchInHashTable(int key,int& locn)
{
int hashIndex=hash(key);
datanode *searchNode=hashTable[hashIndex]->first;
while(searchNode!=NULL)
{
if (searchNode->data==key)
{
locn=hashIndex;
return true;
}
searchNode=searchNode->link;
}
return false;
}
void display()
{
int walker=0;
while(walker<MAX_SIZE)
{
datanode *temp=hashTable[walker]->first;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->link;
}
walker++;
}
}
};
int main()
{
HashTable h;
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
result=h.insertToHashTable(data);
if (result==1)
    cout<<"Inserted into hash table successfully.";
break;
case 2:
cout<<"Enter the element you want to delete:";
cin>>data;
result=h.deleteFromHashTable(data);
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
result=h.searchInHashTable(data,locn);
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