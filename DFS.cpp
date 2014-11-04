#include<stdio.h>
#include<iostream>
#include<string.h>
#include<list>
#include<stdlib.h>
#include<stack>
using namespace std;

list <int> adj[10000];  //Adjecency List with predefined number of vertices(10000)

void dfs(int start,int end)   //DFS Function(prints the order of visited nodes)
{
	bool visited[1000000]={0};
	stack<int>D;
	int count=0;  //For finding number of computations in DFS.
	D.push(start);
	while(!D.empty())
	{
	   int	next = D.top();
        D.pop();
		list<int>::iterator it=adj[next].begin();
		for(;it!=adj[next].end();it++)
		{
			if(!visited[*it])
			{
				cout<<*it<<" ";
				count++;
				if(*it==end){return;}
			   D.push(*it);
			   visited[*it]=1;
		    }
		} 		
		
	}
	printf("Number of computations = %d\n",count);
}

int main()
{
	int E,V,start,end,a,b;
	char c;
	printf("Enter Number of Vertices\n");
    scanf("%d",&V);	
	printf("Enter Number of Edges\n");
	scanf("%d",&E);
	printf("Enter Edges\n");
	for(int i=0;i<E;i++)
	{
		scanf("%d%c%c%d",&a,&c,&c,&b);
		adj[a].push_back(b);            
		adj[b].push_back(a);            //Assuming graph to be non directed.
	}
	printf("Enter Starting point\n");
	scanf("%d",&start);
	printf("Enter Destination node number\n");	
	scanf("%d",&end);
	dfs(start,end);   //Function Calling
	return 0;
}


