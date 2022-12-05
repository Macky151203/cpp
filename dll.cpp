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
list->head=list->rear=NULL;

list->count=0;
}
bool insertDLL(int dataIn)
{
datanode *pNew=new datanode;
pNew->data=dataIn;
pNew->back=pNew->fore=NULL;
if(pPre==NULL)
{
pNew->fore=list->head;
if(list->head!=NULL){
list->head->back=pNew;
pNew->back=list->rear;
list->rear->fore=pNew;
list->head=pNew;
}
else{
    list->head=list->rear=pNew;
}
}
else
{
pNew->fore=pPre->fore;
pNew->back=pPre;
if(pPre->fore!=NULL)
pPre->fore->back=pNew;
else{
    pNew->fore=list->head;
    list->head->back=pNew;
    list->rear=pNew;

}
pPre->fore=pNew;

}
list->count++;
}
bool deleteDLL(int &dataOut)
{
dataOut=pLoc->data;
if (pLoc->back!=NULL)
pLoc->back->fore=pLoc->fore;
else{
    pLoc->fore->back=pLoc->back;
    pLoc->back->fore=pLoc->fore;
list->head=pLoc->fore;
}
if (pLoc->fore!=NULL)
pLoc->fore->back=pLoc->back;
else{
    pLoc->back->fore=pLoc->fore;
    pLoc->fore->back=pLoc->back;
    list->rear=pLoc->back;

}

list->count--;
delete pLoc;
return true;
}
bool searchList(int target)
{
pPre=NULL;
pLoc=list->head;
while(pLoc!=NULL && pLoc->data<target)
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


bool addNode(int dataIn)
{
bool found=searchList(dataIn);
bool success;
if(found)
success=false;
else
success=insertDLL(dataIn);
return success;
}
bool removeNode(int& dataOut)
{
bool found=searchList(dataOut);
bool success;
if(found)
success=deleteDLL(dataOut);
else
success=false;
return success;
}

void display()
{
datanode *pWalker=list->head;
cout<<pWalker->data;
pWalker=pWalker->fore;
while(pWalker!=list->head)
{
cout<<pWalker->data<<" ";
pWalker=pWalker->fore;
}
}
bool emtpyList()
{
if (list->count==0)
return true;
else
return false;
}
int dllCount()
{
return list->count;
}

};
int main()
{
CircularDoublyLinkedList d;
bool result;
int choice,i=1,data,target;
while(i==1)
{
cout<<"\n\n1.Insert\n2.Delete\n3.Empty\n4.Count\n5.Display\n6.Exit\nEnter choice:";
cin>>choice;
switch(choice)
{
case 1:
cout<<"Enter the element you want to insert:";
cin>>data;
result=d.addNode(data);
if (result)
cout<<"Inserted element successfully.";
else
cout<<"Duplicate element.Can't Insert";
break;
case 2:
cout<<"Enter the element you want to delete:";
cin>>data;
result=d.removeNode(data);
if (result)
cout<<"Deleted element "<<data<<" successfully.";
else
cout<<"Element is not found.";
break;
case 3:
result=d.emtpyList();
if (result)
cout<<"List is empty.";
else
cout<<"List is not empty.";
break;
case 4:
data=d.dllCount();
cout<<"Number of elements in list:"<<data;
break;

case 5:
if (d.emtpyList())
cout<<"List is empty.";
else
{
cout<<"Elements in list:";
d.display();
}
break;


default:
i=0;
}
}

}