#include<iostream>
using namespace std;
struct datanode{
    int data;
    datanode *link;
};
struct  headnode{
    int count;
    datanode *front;
    datanode *rear;
};
class linkedq{
    headnode *queuehead;
    public:
        linkedq(){
            queuehead = new headnode;
            queuehead->count=0;
            queuehead->front=NULL;
            queuehead->rear=NULL;
        }
        bool eq(int data){
            datanode *t= new datanode;
            t->data=data;
            t->link=NULL;
            if(queuehead->rear==NULL){
                queuehead->front=t;
            }
            else{
                queuehead->rear->link=t;
            }
            queuehead->rear=t;
            queuehead->count++;
            return true;
        }
        bool dq(){
            int dataout;
            if(queuehead->count==0){
                return false;
            }
            else{
                datanode *t= queuehead->front;
                dataout=t->data;
                queuehead->front=t->link;
                if(queuehead->front==NULL){
                    queuehead->rear=NULL;
                }
                queuehead->count--;
                return true;
            }

        }
        bool qfront(){
            int data;
            if(queuehead->count==NULL){
                return false;
            }
            else{
                data=queuehead->front->data;
                cout<<data<<endl;
                return true;
            }
        }

};