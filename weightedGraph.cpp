#include <iostream>
using namespace std; 
class stack{
	public:
		int size;
		int *arr;
		int top;

		stack(int s){
			size =s;
			arr = new int[size];
			top=-1;
		}
	
		bool is_empty(){
			if(top == -1){
				return true;
			}
			else{
				return false;
			}
		}
		bool is_full(){
			if(top == size-1){
				return true;
			}
			else{
				return false;
			}
		}
		void push(int x){
			if(!is_full()){
				arr[++top] = x;
			}
			else{
				cout<<"Array is Full."<<endl;
			}
		
		}
		int pop(){
			if(is_empty()){
				cout<<"No value to POP"<<endl;
			}
			else{
				if (top==0){
					top=-1;
				}
				else{
					return  arr[top--];
					
				}
			}
			
		}
		void display(){
			int i=0; 
			while (i<=top){
				cout<<arr[i]<" ";
				i++;
				
			}
		}
		
};








int vertArr[20][20]; //the adjacency matrix initially 0
int count = 0;
void display(int v) {
   int i, j;
   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
         cout << vertArr[i][j] << " ";
      }
      cout << endl;
   }
}


	

void add_edge(int u, int v) {       //function to add edge into the matrix
   vertArr[u][v] = 1;
   vertArr[v][u] = 1;
}
void BFS(){
	int visited[] = {0,0,0,0,0};
	stack s1(10);
	for(int i = 0;i<=5;i++){
		s1.push(i);
		bool b = false;
		int t = s1.pop();
		for (int i = 0; i<5;i++){
			if(t==visited[i]){
				 b = true;
				 break;
			}
		}
		if(!b){
			visited[i]=t;
		}
		for(int j = 0; j<=5;j++){
			if(vertArr[i][j]==1){
				s1.push(i);								
			}	
		}
	}
	for(int i = 0; i<5;i++){
		if(visited[i]!=0){
		cout<<"Visited nodes are: "<<visited[i]<<endl;}
	}
	cout<<endl;
	s1.display();
	
}
int main(){
	stack s1(5);
	
	
	cout<<"Enter the number of vertices in THe Graph: ";
	int vertices;
	
	cin>>vertices; 
	 
	
	
	int opt;
	do{
		cout<<"Enter 1 to add edge between 2 points"<<endl;
		cout<<"Enter 2 to Dislay the Graph "<<endl;
		cin>>opt;
		
		switch(opt){
			case 1:
				cout<<"Enter the 2 edges: ";
				
				int i,j;
		        cin>>i;
		        cin>>j;
//		        int weight;
//		        cout<<"Enter the Weight of the Edge: ";
//		        cin>>weight; 
		        
		        add_edge(i,j);
		        break;
		    case 2:
		    	display(vertices);
		    	break;
		    case 3:
		    	BFS();
		    	
		    	
				
		}
		
	
		
	}
	while (opt!=0);
	return 0; 
	
}


