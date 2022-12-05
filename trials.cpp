
#include <iostream>
#define MAX 10
using namespace std;

struct node
{
	int ver;
	node *next;
};

struct vertex
{
	string name;
	bool processed;
	node *adjptr;
};

class Stack
{
	private:
		int arr[MAX];
		int top=-1;
		bool success;
		bool empty;
	public:
		bool pushStack(int datain)
		{
			success=true;
			if(top==MAX)
			{
				success=false;
			}
			else
			{
				++top;
				arr[top]=datain;
				success=true;
			}
			return success;
		}
		
		int popStack(int &dataout)
		{
			success= true;
			if(top==-1)
			{
				success = false;
			}
			else
			{
				dataout=arr[top];
				top--;
				success=true;
			}
			return success;
		}
		
		bool isEmpty()
		{
			if(top==-1)
			{
				empty=true;
			}
			else
			{
				empty=false;
			}
		    return empty;
		}
};

class Graph
{
	private:
		vertex G[10];
		int n;
	public:
		void createGraph()
		{
			cout<<"enter no of vertices:";
			cin>>n;
			for(int i=0;i<n;i++)
			{
				int m;
				cout<<"enter name of the vertex:";
				cin>>G[i].name;
				cout<<"enter no of adjecent vertices for vertex "<<G[i].name<<" :";
				cin>>m;
				G[i].adjptr=NULL;
				for(int j=0;j<m;j++)
				{
					node *t=new node;
					cout<<"enter index of adjacent vertex "<<j<<" :";
					cin>>t->ver;
					t->next=G[i].adjptr;
					G[i].adjptr=t;
				}
			}
		}
		
		void DisplayGraph()
		{
			for(int i=0;i<n;i++)
			{
				cout<<G[i].name<<"  ";
				cout<<G[i].processed<<"  ";
				node *t=G[i].adjptr;
				while(t!=NULL)
				{
					cout<<"-->"<<t->ver;
					t=t->next;
				}
				cout<<endl;
			}
		}
		
		void DFS(){
			Stack s;
			int u;
			for(int i=0;i<n;i++){
				G[i].processed=false;
			}
			for(int i=0;i<n;i++){
				if(G[i].processed==false){
					s.pushStack(i);
					while(!s.isEmpty()){
						s.popStack(u);
						if(G[u].processed==false){
							cout<<G[u].name;
							G[u].processed=true;
							node *t= G[u].adjptr;
							while(t!=NULL){
								int v= t->ver;
								s.pushStack(v);
								t=t->next;
							}
						}
					}
				}
			}
			cout<<endl;
		}
};

int main()
{
	Graph gp;
	
	gp.createGraph();
	cout<<"enter index of the source vertex:";
	
	cout<<"Breath First Traversal Order:"<<endl;
	gp.DFS();
	cout<<endl<<"graph : "<<endl;
	gp.DisplayGraph();
	return 0;
}

