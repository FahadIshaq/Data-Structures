#include <iostream>
using namespace std;


    struct Node
    {
        int data;
        struct Node *next;
    };
    Node *front = NULL;
    Node *rear = NULL;
    int size = 5;
    int pos = 0;

void enQueue(int x){
    Node *temp = new Node;
    temp->data=x;
    temp->next=NULL;
    if (pos==size){
        cout<<"Queue is Full\n";
        return;
    }
    if(rear==NULL){
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
    pos++;
}

void deQueue(){
    if(front==NULL)
    cout<<"Queue is Empty";
    else
    {
        Node *temp = front;
        front=front->next;
        pos--;
        delete(temp);
    }
    if(front==NULL)
    rear=NULL;
}

void display(){
    if(front == NULL)
    return;

    Node *temp = front;
    while(temp!=rear->next){
    cout<<temp->data<<" "<<endl;;
    temp=temp->next;
    }
}

bool isEmpty()
{
    if(front==NULL)
    return true;

    return false;
}

void BFS(int cost [7][7],int vertices, int start){

    bool visited[7]={false};

    int index = 0;
    int out [7] = {0};

    out [index] = start;
    index++;

    visited[start]=true;
    enQueue(start);
    while(!isEmpty()){
        int i = front->data;
        deQueue();
        for(int j = 0 ;j<vertices ; j++){
            if(cost[i][j]==1 && visited[j]==false)
            {
                out[index]=j;
                index++;
                visited [j] =true;
                enQueue(j);
            }
        }
    }
    for (int  i = 0 ; i<vertices ; i++){
        if(out[i]!=0)
        cout<<out[i]<<endl;;
    }
}



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






int main()
    {
    	
    	
	cout<<"Enter the number of vertices in THe Graph: ";
	int vertices;
	
	cin>>vertices; 
	

	 	
	
	int opt;
	do{
		cout<<"Enter 1 to add edge between 2 points"<<endl;
		cout<<"Enter 2 to Dislay the Graph "<<endl;
		cout<<"Enter 3 to view BFS traversal of the Graph(Example) "<<endl;
		cin>>opt;
		
		switch(opt){
			case 1:
				cout<<"Enter the 2 edges: ";
				
				int i,j;
		        cin>>i;
		        cin>>j;
		        add_edge(i,j);
		        break;
		    case 2:
		    	display(vertices);
		    	break;
		    case 3:
		    	{
				
		    	int start;
        int cost[7][7]= 
        { 
                {0,0,0,0,0,0,0},
                {0,0,1,1,0,0,0},
                {0,1,0,0,1,0,0},
                {0,1,0,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}
        }; 
        

        cout<<"Enter the starting vertex: ";
        cin>>start;
        BFS(cost,7,start);
    }
		    	
				
		}
		
	
		
	}
	while (opt!=0);
	
	
        

        
	}  
