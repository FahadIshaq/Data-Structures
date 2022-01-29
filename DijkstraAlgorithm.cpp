#include<iostream>
#include<climits>     
using namespace std;

int minimumDistance(int distance[], bool visited[]);

void DijkstraAlgorithm(int graph[9][9],int start);



int main()
{
	int graph[9][9]= 
        { 
                { 0, 4, 999, 999, 999, 999, 999, 8, 999 }, 
                { 4, 999, 8, 999, 999, 999, 999, 11, 999 }, 
                { 999, 8, 999, 7, 999, 4, 999, 999, 2 }, 
                { 999, 999, 7, 999, 9, 14, 999, 999, 999 }, 
                { 999, 999, 999, 9, 999, 10, 999, 999, 999 }, 
                { 999, 999, 4, 14, 10, 999, 2, 999, 999 }, 
                { 999, 999, 999, 999, 999, 2, 999, 1, 6 }, 
                { 8, 11, 999, 999, 999, 999, 1, 999, 7 }, 
                { 999, 999, 2, 999, 999, 999, 6, 7, 999 } 
            }; 

	DijkstraAlgorithm(graph,0);
	return 0;	                        
}
int minimumDistance(int distance[], bool visited[]) 
{
	int minimumValue=INT_MAX,index;
              
	for(int i=0;i<9;i++) 
	{
		if(visited[i]==false && distance[i]<=minimumValue)      
		{
			minimumValue=distance[i];
			index=i;
		}
	}
	return index;
}
void DijkstraAlgorithm(int graph[9][9],int start) 
{
	int distance[9];                            
	bool visited[9];
	for(int i = 0; i<9; i++)
	{
		distance[i] = INT_MAX;
		visited[i] = false;	
	}
	
	distance[start] = 0;              
	
	for(int i = 0; i<9; i++)                           
	{
		int m=minimumDistance(distance,visited); 
		visited[m]=true;
		for(int i = 0; i<9; i++)                  
		{
		
			if(!visited[i] && graph[m][i] && distance[m]!=INT_MAX && distance[m]+graph[m][i]<distance[i])
				distance[i]=distance[m]+graph[m][i];
		}
	}
	cout<<"Vertex\t\tDistance from source"<<endl;
	for(int i = 0; i<9; i++)                      
	{ 
		cout<<i<<"\t\t\t"<<distance[i]<<endl;
	}
}

