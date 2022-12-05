#include<iostream>
using namespace std;
struct datanode
{
datanode *back;
int data;
datanode *fore;
};
struct headnode
{
int count;
datanode *rear;
datanode *head;
};
class CircularDoublyLinkedList
{
headnode *list;
datanode *pPre,*pLoc;
public:
CircularDoublyLinkedList()
{
list=new headnode;
list->head=NULL;
list->rear=NULL;
list->count=0;
}
bool searchList(int target)
{
pPre=NULL;
pLoc=list->head;
if(pLoc!=NULL && pLoc->data<target)
{
pPre=pLoc;
pLoc=pLoc->fore;
}
while(pLoc!=list->head && pLoc->data<target)
{
pPre=pLoc;
pLoc=pLoc->fore;
}
if (pLoc==NULL)
return false;
else if(pLoc->data==target)
return true;
else
return false;
}
bool insertCDLL(int dataIn)
{
bool found=searchList(dataIn);
bool success;
if(found)
success=false;
else{
datanode *pNew=new datanode;
pNew->data=dataIn;
if(pPre==NULL)
{
if(list->head!=NULL)
{
pNew->fore=list->head;
pNew->back=list->rear;
list->head->back=pNew;
list->rear->fore=pNew;
}
else
{
pNew->fore=pNew;
pNew->back=pNew;
list->rear=pNew;
}
list->head=pNew;
}
else
{
pNew->fore=pPre->fore;
pNew->back=pPre;
pPre->fore->back=pNew;
pPre->fore=pNew;
if(list->rear==pPre)
list->rear=pNew;
}
list->count++;
success=true;
}
return success;
}
bool deleteCDLL(int &dataOut)
{
bool found=searchList(dataOut);
bool success;
if(found)
{
dataOut=pLoc->data;
if(list->count==1){
list->head=list->rear=NULL;
}
else{
if(pPre!=NULL)
{
pPre->fore=pLoc->fore;
pLoc->fore->back=pPre;
if(list->rear==pLoc)
list->rear=pPre;
}
else{
list->head=pLoc->fore;
pLoc->fore->back=pLoc->back;
list->rear->fore=pLoc->fore;
}
}
list->count--;
delete pLoc;
success=true;
}
else
success=false;
return success;
}
int searchCDLLFromHead(int target)
{
pLoc=list->head;
int pos=1;
if(pLoc!=NULL && target>pLoc->data)
{
pos++;
pLoc=pLoc->fore;
}
while(pLoc!=list->head && target>pLoc->data)
{
pos++;
pLoc=pLoc->fore;
}
if (pLoc==NULL)
return -1;
else
{
if(target==pLoc->data)
return pos;
else
return -1;
}
}
int searchCDLLFromRear(int target)
{
pLoc=list->rear;
int pos=1;
if(pLoc!=NULL && target<pLoc->data)
{
pos++;
pLoc=pLoc->back;
}
while (pLoc!=list->rear && target<pLoc->data)
{
pos++;
pLoc=pLoc->back;
}
if (pLoc==NULL)
return -1;
else
{
if(target==pLoc->data)
return pos;
else
return -1;
}
}
void displayHeadToRear()
{
datanode *pWalker=list->head;
if(pWalker!=NULL)
{
cout<<pWalker->data<<" ";
pWalker=pWalker->fore;
}
while(pWalker!=list->head)
{
cout<<pWalker->data<<" ";
pWalker=pWalker->fore;
}
}
void displayRearToHead()
{
datanode *pWalker=list->rear;
if(pWalker!=NULL)
{
cout<<pWalker->data<<" ";
pWalker=pWalker->back;
}
while(pWalker!=list->rear)
{
cout<<pWalker->data<<" ";
pWalker=pWalker->back;
}
}
bool emtpyCDLL()
{
if (list->count==0)
return true;
else
return false;
}
int cdllCount()
{
return list->count;
}
~CircularDoublyLinkedList()
{
datanode *temp=list->head;
while(list->count!=0)
{
list->head=temp->fore;
delete temp;
list->count--;
temp=list->head;
}
list->head=list->rear=NULL;
}
};
int main()
{
CircularDoublyLinkedList cd;
bool result;
int choice,i=1,data,target;
while(i==1)
{
cout<<"\n\n1.Insert\n2.Delete\n3.Empty\n4.Count\n5.Search from head\n6.Search from rear\n7.Display from head\n8.Display from rear\n9.Exit\nEnter choice:";
cin>>choice;
switch(choice)
{
case 1:
cout<<"Enter the element you want to insert:";
cin>>data;
result=cd.insertCDLL(data);
if (result)
cout<<"Inserted element successfully.";
else
cout<<"Duplicate element.Can't Insert";
break;
case 2:
cout<<"Enter the element you want to delete:";
cin>>data;
result=cd.deleteCDLL(data);
if (result)
cout<<"Deleted element "<<data<<" successfully.";
else
cout<<"Element is not found.";
break;
case 3:
result=cd.emtpyCDLL();
if (result)
cout<<"List is empty.";
else
cout<<"List is not empty.";
break;
case 4:
data=cd.cdllCount();
cout<<"Number of elements in list:"<<data;
break;
case 5:
cout<<"Enter the element you want to search:";
cin>>target;
data=cd.searchCDLLFromHead(target);
if (data==-1)
cout<<"Element not found.";
else
cout<<"Element found at position "<<data<<" from head.";
break;
case 6:
cout<<"Enter the element you want to search:";
cin>>target;
data=cd.searchCDLLFromRear(target);
if (data==-1)
cout<<"Element not found.";
else
cout<<"Element found at position "<<data<<" from rear.";
break;
case 7:
if (cd.emtpyCDLL())
cout<<"List is empty.";
else
{
cout<<"Elements in list:";
cd.displayHeadToRear();
}
break;
case 8:
if (cd.emtpyCDLL())
cout<<"List is empty.";
else
{
cout<<"Elements in list:";
cd.displayRearToHead();
}
break;
default:
i=0;
}
}

}