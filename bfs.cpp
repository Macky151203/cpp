#include<iostream>
#define MAX_SIZE 10
using namespace std;
struct node{
	int ver;
	node *next;
};
struct vertex{
	string name;
	bool processed;
	node *adjptr;
};
class Queue{
	int arr[10];
	int datain;
	int front,rear;
	bool success,empty,full;
	public:
		Queue(){
			datain=0;
			front=rear=-1;
		}
		bool Enqueue(int d){
			datain=d;		
			if(sizeof(arr)==MAX_SIZE){
				success=false;
			}
			else{
				rear++;
				arr[rear]=datain;
				if(front==-1)
					front=0;
				success=true;
			}
			return success;
		}
		bool Dequeue(int &dataout){	
			if(sizeof(arr)==0){
				success=false;
			}
			else{
				dataout=arr[front];
				if(front==rear){
					front=rear=-1;
				}
				else{
					front++;
					success=true;
				}				
			}
			return success;
		}
		bool EmptyQueue(){
			if(front==-1 && rear==-1){
				empty=true;
			}
			else{
				empty=false;
			}
			return empty;
		}
};
class Graph{
	vertex G[10];
	int n,m;
	public:
		void creategraph(){
			cout<<"Number of vertices : ";
			cin>>n;
			for(int i=0 ;i<n ;i++){
				cout<<"Enter the name of vertex : ";
				cin>>G[i].name;
				cout<<"Enter no of adj vertices for vertex "<<G[i].name<<":";
				cin>>m;
				G[i].adjptr = NULL;
				for(int j=0 ;j<m ;j++){
					node *t=new node;
					cout<<"Enter index of adj vertex "<< j <<" :";
					cin>>t->ver;
					t->next = G[i].adjptr;
					G[i].adjptr = t;
				}
			}
		}
		void display(){
			for(int i=0 ;i<n ;i++){
				cout<<G[i].name<<":";
				node *t = G[i].adjptr;
				while(t != NULL){
					cout<<"-->"<<t->ver;
					t=t->next;
				}
				cout<<endl;
			}
		}
		void BFS(int s){
			Queue q;
			int u;
			for(int i=0;i<n;i++){
				G[i].processed=false;
			}
			q.Enqueue(s);
			G[s].processed=true;
			while(!q.EmptyQueue()){
				q.Dequeue(u);
				cout<<G[u].name<<",";
				node *t=G[u].adjptr;
				while(t!=NULL){
					int v=t->ver;
					if(!G[v].processed){
						q.Enqueue(v);
						G[v].processed = true;
					}
					t=t->next;
				}
			}
			cout <<endl;
		}
};
int main(){
	Graph graph;
	int s;
	graph.creategraph();
	cout<<"GRAPH :"<<endl;
	graph.display();
	cout<<"Enter the source node :";
	cin>>s;
	graph.BFS(s);
	return 0;
}

