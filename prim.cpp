#include <iostream>
#include <limits>
#define MAX 10
using namespace std;

struct node
{
	int ver;
	int weight;
	node *next;
};

struct vertex
{
	string name;
	bool inTree;
	int key;
	int par;
	node *adjptr;
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
				cout<<"\nenter name of the vertex:";
				cin>>G[i].name;
				cout<<"enter no of adjecent vertices for vertex "<<G[i].name<<" :";
				cin>>m;
				G[i].adjptr=NULL;
				for(int j=0;j<m;j++)
				{
					node *t=new node;
					cout<<"enter index of adjacent vertex "<<j<<" :";
					cin>>t->ver;
					cout<<"enter weight of edge "<<j<<" :";
					cin>>t->weight;
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
				cout<<G[i].inTree<<"  ";
				node *t=G[i].adjptr;
				while(t!=NULL)
				{
					cout<<"-->("<<t->ver<<" : "<<t->weight<<")";
					t=t->next;
				}
				cout<<endl;
			}
		}
		
		void MWST_prims()
		{
			int v,total=0;
			for(int i=0;i<n;i++)
			{
				G[i].inTree=false;
				G[i].key=INT_MAX;
				G[i].par=-1;
			}
			G[0].key=0;
			cout<<"edges included in the spanning tree:\n";
			for(int i=0;i<n;i++)
			{
				int minkey=INT_MAX;
				for(int j=0;j<n;j++)
				{
					if (!G[j].inTree && minkey>G[j].key)
					{
						minkey=G[j].key;
						v=j;
					}
				}
				if(G[v].par!=-1)
				{
					cout<<G[G[v].par].name<<"-->"<<G[v].name<<" : "<<G[v].key<<endl;
					total=total+G[v].key;
					
				}
				G[v].inTree=true;
				node *t=G[v].adjptr;
				while(t!=NULL)
				{
					int u=t->ver;
					if(!G[u].inTree && t->weight<G[u].key)
					{
						G[u].key=t->weight;
						G[u].par=v;
					}                    
					t=t->next;
				}
			}
			cout<<"spanning tree total weight"<<total<<endl;
		}
		
};

int main()
{
	Graph gp;
	int s;
	gp.createGraph();
	gp.MWST_prims();
	cout<<endl<<"graph : "<<endl;
	gp.DisplayGraph();
	return 0;
}